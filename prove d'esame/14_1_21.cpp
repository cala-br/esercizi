#include <iostream>
#include <fstream>
using namespace std;


struct UsersQueue {
    char *_users;
    int _head;
    int count;
    int maxSize;
};


enum CopyComparison {
    COMPARE_EQUAL,
    COMPARE_NOT_EQUAL,
};


bool isServiceCodeValid(char code) {
    return 'A' <= code && code <= 'Z';
}

void initQueue(UsersQueue& queue) {
    queue._users = NULL;
    queue._head = 0;
    queue.count = 0;
    queue.maxSize = 0;
}

void updateQueueSize(UsersQueue& queue, const int newSize) {
    if (queue._users != NULL)
        delete[] queue._users;

    initQueue(queue);

    queue._users = new char[newSize];
    queue.maxSize = newSize;
}


bool isQueueEmpty(UsersQueue& queue) {
    return queue.count == 0;
}

bool isQueueFull(UsersQueue& queue) {
    return queue.count == queue.maxSize;
}

void _queueIncrementHead(int& head, const int maxSize) {
    ++head %= maxSize;
}


bool tryEnqueueUser(UsersQueue& queue, char serviceCode) {
    if (!isServiceCodeValid(serviceCode))
        return false;

    if (isQueueFull(queue))
        return false;

    queue._users[queue._head] = serviceCode;

    _queueIncrementHead(queue._head, queue.maxSize);
    queue.count++;
    return true;
}


int _getDequeueIndex(UsersQueue& queue) {
    int result = 
        queue._head - queue.count;

    return result < 0
        ? queue.maxSize + result
        : result;
}

bool tryDequeueUser(UsersQueue& queue, char& user) {
    if (isQueueEmpty(queue))
        return false;

    int targetIndex = 
        _getDequeueIndex(queue);

    user = queue._users[targetIndex];
    queue.count--;
    return true;
}


void printQueue(UsersQueue& queue, ostream& out) {
    int j = _getDequeueIndex(queue);

    for (int i = 0; i < queue.count; i++) {
        out << queue._users[j] << ' ';
        _queueIncrementHead(j, queue.maxSize);
    }
}

void dumpQueue(UsersQueue& queue, ostream& out) {
    out << queue.maxSize << '\n';
    out << queue.count << '\n';
    out << queue._head << '\n';

    printQueue(queue, out);
}


void loadQueue(UsersQueue& queue, istream& in) {
    in >> queue.maxSize;
    updateQueueSize(queue, queue.maxSize);

    in >> queue.count;
    in >> queue._head;

    int j = _getDequeueIndex(queue);

    for (int i = 0; i < queue.count; i++) {        
        in >> queue._users[j];
        _queueIncrementHead(j, queue.maxSize);
    }
}


void enqueueFromIf(UsersQueue& from, UsersQueue& to, char code, CopyComparison compare) {
    char *users = from._users;
    int j = _getDequeueIndex(from);

    for (int i = 0; i < from.count; i++) {
        bool shouldEnqueue = compare == COMPARE_EQUAL
            ? users[i] == code
            : users[i] != code;

        if (shouldEnqueue)
            tryEnqueueUser(to, users[j]);

        _queueIncrementHead(j, from.maxSize);
    }
}


void anticipateService(UsersQueue& queue, char serviceCode) {
    if (!isServiceCodeValid(serviceCode))
        return;

    UsersQueue result;
    initQueue(result);
    updateQueueSize(result, queue.maxSize);

    char *users = queue._users;
    
    enqueueFromIf(queue, result, serviceCode, COMPARE_EQUAL);
    enqueueFromIf(queue, result, serviceCode, COMPARE_NOT_EQUAL);

    delete[] queue._users;
    queue = result;
}


int main()
{
    UsersQueue queue;
    initQueue(queue);

    const char *DUMP_FILE_PATH = "queue.dump";
    const char *MENU = 
        "1. Inizializza coda\n"
        "2. Accoda utente\n"
        "3. Stampa coda\n"
        "4. Salva coda\n"
        "5. Carica coda\n"
        "6. Servi prossimo utente\n"
        "7. Anticipa servizio\n"
        "8. Esci\n"
        " >> ";

    while (true)
    {
        int opt;
        cout << MENU;
        cin >> opt;

        switch(opt)
        {
            case 1: {
                int newSize;
                cout << "Inserirsci la nuova lunghezza: ";
                cin >> newSize;

                updateQueueSize(queue, newSize);
                break;
            }

            case 2: {
                char serviceCode;
                cout << "Inserisci il codice di servizio: ";
                cin >> serviceCode;

                if (!tryEnqueueUser(queue, serviceCode)) {
                    cerr << "Codice non valido o dimensione massima raggiunta";
                }

                break;
            }

            case 3:
                printQueue(queue, cout);
                break;

            case 4: {
                ofstream out(DUMP_FILE_PATH);
                dumpQueue(queue, out);
                out.close();
                break;
            }

            case 5: {
                ifstream in(DUMP_FILE_PATH);
                loadQueue(queue, in);
                in.close();
                break;
            }

            case 6: {
                char user;
                if (!tryDequeueUser(queue, user)) {
                    cerr << "La coda è vuota";
                }
                else {
                    cout << "Servito utente " << user;
                }

                break;
            }

            case 7: {
                char serviceCode;
                cout << "Servizio da anticipare: ";
                cin >> serviceCode;

                anticipateService(queue, serviceCode);
                break;
            }

            case 8:
                return 0;
        }

        cout << endl;
    }    
}