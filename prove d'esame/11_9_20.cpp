#include <iostream>
#include <fstream>

using namespace std;


enum MemoryAction {
    MEMORY_ACTION_BAD_ACTION,
    MEMORY_ACTION_ALLOCATION = 'A',
    MEMORY_ACTION_ACCESS = 'X',
    MEMORY_ACTION_DEALLOCATION = 'D',
};

struct MemoryOperation {
    MemoryAction action;
    unsigned int address;
};

struct MemoryOperationSequence {
    MemoryOperation *_operations;
    unsigned int _count;
    unsigned int _length;
};


MemoryAction getActionFrom(char c) {
    switch (c) {
        case 'A':
        case 'X':
        case 'D': return static_cast<MemoryAction>(c);
    }
    return MEMORY_ACTION_BAD_ACTION;
}


void initSequence(MemoryOperationSequence& sequence) {
    sequence._operations = NULL;
    sequence._count = 0;
    sequence._length = 0;
}

void updateSequenceLength(
    MemoryOperationSequence& sequence, 
    const unsigned int length
) {
    if (sequence._operations != NULL) 
        delete[] sequence._operations;

    sequence._operations = new MemoryOperation[length];
    sequence._length = length;
}

bool isSequenceFull(MemoryOperationSequence& sequence) {
    return sequence._count == sequence._length;
}

bool sequenceTryAdd(
    MemoryOperationSequence& sequence, 
    MemoryAction action, 
    int code
) {
    if (isSequenceFull(sequence))
        return false;

    sequence._operations[sequence._count] = {
        action,
        code,
    };

    sequence._count++;
}


void printOperation(MemoryOperation& operation, ostream& out) {
    out << operation.address << ' '
        << operation.action << '\n';
}

void printSequence(MemoryOperationSequence& sequence, ostream& out) {
    for (int i = 0; i < sequence._count; i++) {
        printOperation(sequence._operations[i], out);
    }
}


bool trySaveSequence(MemoryOperationSequence& sequence, ostream& out) {
    if (!out)
        return false;

    out << sequence._length;
    printSequence(sequence, out);
    return true;
}


bool loadOperation(MemoryOperation& operation, istream& in) {
    char action;
    in >> action;
    operation.action = getActionFrom(action);
    in >> operation.address;
}

bool tryLoadSequence(MemoryOperationSequence& sequence, istream& in) {
    if (!in)
        return false;

    in >> sequence._length;
    updateSequenceLength(sequence, sequence._length);

    for (int i = 0; i < sequence._count; i++) {
        loadOperation(sequence._operations[i], in);
    }
}