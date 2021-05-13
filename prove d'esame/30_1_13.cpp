#include <iostream>
#include <fstream>

using namespace std;


void swap(int& a, int& b) {
    a ^= b ^= a ^= b;
}


enum PrintOption {
    PRINT_OPT_NONE,
    PRINT_STACK_INFO,
};


struct Stack {
    int *_data;
    int count;
    int maxSize;
};

void stackInit(Stack& stack);
void stackUpdateSize(Stack& stack, const int newSize);
bool stackIsFull(Stack& stack);
bool stackTryPush(Stack& stack, int value);
void stackPrint(Stack& stack, ostream& out, PrintOption printOption);
void stackLoadFromFile(Stack& stack, istream& in);


const int MAX_STACKS = 3;
struct StackBag {
    Stack _stacks[MAX_STACKS];
    int _orderedIndexes[MAX_STACKS];
    int count;
    int maxChildrenSize;
};

void stackBagInit(StackBag& bag);
void stackBagUpdateSize(StackBag& bag, const int newSize);
bool stackBagIsIndexValid(StackBag& bag, int index);
bool stackBagTryPush(StackBag& bag, int value, int index);
void stackBagRearrangeOrderedIndexes(StackBag& bag, int index);
void stackBagPrint(StackBag& bag, ostream& out, PrintOption printOption);
void stackBagMaybePrintInfo(StackBag& bag, ostream& out, PrintOption printOption);
void stackBagPrintOrdered(StackBag& bag, ostream& out);
void stackBagLoadFromFile(StackBag& bag, istream& in);


int main()
{
    const char *DUMP_FILE_PATH = "bag.dump";
    const char *MENU = 
        "1. Modifica capienza\n"
        "2. Inserisci valore\n"
        "3. Stampa insieme\n"
        "4. Salva insieme\n"
        "5. Carica insieme\n"
        "6. Stampa contenuto ordinato\n"
        "7. Esci\n"
        " >> ";

    StackBag bag;
    stackBagInit(bag);
    
    while (true)
    {
        cout << MENU;

        int opt;
        cin >> opt;

        switch (opt)
        {
        case 1: {
            cout << "Capienza: ";
            int newSize;
            cin >> newSize;

            stackBagUpdateSize(bag, newSize);
            break;
        }
        
        case 2: {
            int newValue;
            int index;

            cout << "Valore: ";
            cin >> newValue;

            cout << "Indice: ";
            cin >> index;

            stackBagTryPush(bag, newValue, index);
            break;
        }

        case 3: 
            stackBagPrint(bag, cout, PRINT_OPT_NONE);
            break;

        case 4: {
            ofstream out(DUMP_FILE_PATH);
            stackBagPrint(bag, out, PRINT_STACK_INFO);
            out.close();
        }

        case 5: {
            ifstream in(DUMP_FILE_PATH);
            stackBagLoadFromFile(bag, in);
            in.close();
        }

        case 6:
            stackBagPrintOrdered(bag, cout);
            break;

        case 7:
            return 0;
        }
    }
}



void stackBagInit(StackBag& bag) {
    bag.count = MAX_STACKS;
    bag.maxChildrenSize = 0;
    for (int i = 0; i < bag.count; i++) {
        stackInit(bag._stacks[i]);
        bag._orderedIndexes[i] = i;
    }
}

void stackBagUpdateSize(StackBag& bag, const int newSize) {
    bag.maxChildrenSize = newSize;
    for (int i = 0; i < bag.count; i++) {
        stackUpdateSize(bag._stacks[i], newSize);
    }
}


bool stackBagTryPush(StackBag& bag, int value, int index) {
    if (!stackBagIsIndexValid(bag, index))
        return false;
    
    Stack& target = bag._stacks[index];
    if(!stackTryPush(target, value))
        return false;

    stackBagRearrangeOrderedIndexes(bag, index);
    return true;
}


bool stackBagIsIndexValid(StackBag& bag, int index) {
    return index >= 0 && index < bag.count;
}


void stackBagRearrangeOrderedIndexes(StackBag& bag, int index) {
    const Stack& target = bag._stacks[index];
    int i = 0;

    for (; i < bag.count && bag._orderedIndexes[i] != index; i++)
        ;

    for (int next = i + 1; next < bag.count; next++) {
        const int currentIndex = bag._orderedIndexes[next];
        const Stack& current = bag._stacks[currentIndex];

        if (current.count >= target.count)
            break;

        swap(
            bag._orderedIndexes[next],
            bag._orderedIndexes[next - 1]
        );
    }
}


void stackBagPrint(StackBag& bag, ostream& out, PrintOption printOption) {
    stackBagMaybePrintInfo(bag, out, printOption);

    for (int i = 0; i < bag.count; i++) {
        stackPrint(bag._stacks[i], out, printOption);
    }
}

void stackBagMaybePrintInfo(StackBag& bag, ostream& out, PrintOption printOption) {
    if (printOption == PRINT_STACK_INFO) {
        out << bag.count << '\n'
            << bag.maxChildrenSize << '\n';
    }
    else {
        out << "Capienza: " << bag.maxChildrenSize << '\n';
    }
}


void stackBagPrintOrdered(StackBag& bag, ostream& out) {
    for (int i = 0; i < bag.count; i++) {
        int index = bag._orderedIndexes[i];
        Stack& stack = bag._stacks[index];

        if (stack.count == 0)
            continue;

        out << index << ": ";
        stackPrint(stack, out, PRINT_OPT_NONE);
    }
}


void stackBagLoadFromFile(StackBag& bag, istream& in) {
    stackBagInit(bag);
    in >> bag.count;
    in >> bag.maxChildrenSize;

    for (int i = 0; i < bag.count; i++) {
        stackLoadFromFile(bag._stacks[i], in);
    }
}



void stackInit(Stack& stack) {
    stack._data = NULL;
    stack.count = 0;
    stack.maxSize = 0;
}

void stackUpdateSize(Stack& stack, const int newSize) {
    if (stack._data) {
        delete[] stack._data;
    }

    stack._data = new int[newSize];
    stack.count = 0;
    stack.maxSize = newSize;
}


bool stackTryPush(Stack& stack, int value) {
    if (stackIsFull(stack))
        return false;

    stack._data[stack.count++] = value;
    return true;
}

bool stackIsFull(Stack& stack) {
    return stack.count == stack.maxSize;
}


void stackPrint(Stack& stack, ostream& out, PrintOption printOption) {
    if (printOption == PRINT_STACK_INFO) {
        out << stack.maxSize << '\n'
            << stack.count << '\n';
    }

    for (int i = stack.count - 1; i >= 0; i--) {
        out << stack._data[i] << ' ';
    }
    out << '\n';
}


void stackLoadFromFile(Stack& stack, istream& in) {
    in >> stack.maxSize;
    stackUpdateSize(stack, stack.maxSize);

    in >> stack.count;
    for (int i = stack.count - 1; i >= 0; i--) {
        in >> stack._data[i];    
    }
}