#include <iostream>
#include <fstream>
using namespace std;

struct Container {
    int position;
    int boxes;
};


struct StorageOperations {
    Container *containers;
    int currentContainerIndex;
    int maxOperations;
};

enum Threshold {
    THRESHOLD_NONE = 0,
    THRESHOLD_V2 = 20,
};


void storageOperationsInit(StorageOperations& ops) {
    ops.containers = NULL;
    ops.currentContainerIndex = 0;
    ops.maxOperations = 0;
}


void storageOperationsUpdateMaxOperations(
    StorageOperations& ops,
    int maxOperations
) {
    if (ops.containers != NULL) {
        delete[] ops.containers;
    }

    ops.containers = new Container[maxOperations];
    ops.currentContainerIndex = 0;
    ops.maxOperations = maxOperations;
}


bool storageOperationsTryAdd(StorageOperations& ops, Container container) {
    if (ops.currentContainerIndex >= ops.maxOperations) {
        return false;
    }
    
    ops.containers[ops.currentContainerIndex] = container;
    ops.currentContainerIndex++;
    return true;
}


bool storageOperationsTryUpdate(
    StorageOperations& ops,
    int index,
    int newBoxes 
) {
    if (index >= ops.maxOperations) {
        return false;
    }

    ops.containers[index].boxes += newBoxes;
    return true;
}


int storageOperationsFindContainer(
    const StorageOperations& ops, 
    int position, 
    int threshold
) {
    for (int i = 0; i < ops.currentContainerIndex; i++) {
        Container c = ops.containers[i];

        bool isTarget = 
            c.position <= position + threshold &&
            c.position >= position - threshold;

        if (isTarget)
            return i;
    }
    return -1;
}


void cambia_max_operazioni(StorageOperations& ops, int maxOperations) {
    storageOperationsUpdateMaxOperations(ops, maxOperations);   
}


bool inserisci_operazione(
    StorageOperations& ops, 
    int position, 
    int boxes
) {
    Container newContainer = {
        position,
        boxes,
    };

    int maybeIndex = 
        storageOperationsFindContainer(ops, position, THRESHOLD_NONE);

    return maybeIndex == -1
        ? storageOperationsTryAdd(ops, newContainer)
        : storageOperationsTryUpdate(ops, maybeIndex, boxes);
}


void storageOperationsDump(const StorageOperations& ops, ofstream& stream) {
    const char *rawOps = reinterpret_cast<const char*>(&ops);
    const int bytesToWrite = sizeof(ops);

    stream.write(rawOps, bytesToWrite);
}


void storageOperationsLoad(StorageOperations& ops, ifstream& stream) {
    char *pOps = reinterpret_cast<char*>(&ops);
    const int bytesToRead = sizeof(ops);

    stream.read(pOps, bytesToRead);
}


void stampa_operazioni(StorageOperations& ops) {
    for (int i = 0; i < ops.currentContainerIndex; i++) {
        Container c = ops.containers[i];

        cout << c.position << ' ' << c.boxes << '\n';
    }
}


void salva_lista(const StorageOperations& ops, ofstream& file) {
    storageOperationsDump(ops, file);   
}

void carica_lista(StorageOperations& ops, ifstream& file) {
    storageOperationsLoad(ops, file);
}


int main()
{
    StorageOperations ops;
    storageOperationsInit(ops);

    ifstream os("boxes_storage.dump");
    carica_lista(ops, os);

    stampa_operazioni(ops);
    return 0;

    cambia_max_operazioni(ops, 10);

    inserisci_operazione(ops, 30, 50);
    inserisci_operazione(ops, 53, 24);
    inserisci_operazione(ops, 41, 10);

    inserisci_operazione(ops, 30, 60);

    stampa_operazioni(ops);
}