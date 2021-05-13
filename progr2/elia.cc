#include <iostream>
#include <fstream>
#include <cstring>

using namespace std; 

void errore(const char *msg) {
  if (msg != NULL)
    cout << msg;

  cout << "\n\nOPS! Qualcosa è andato storto. Riprova\n\n"; 
}

const int dimensioneURL = 51; 

struct elem {
  char URL[dimensioneURL]; 
  elem *prev; 
  elem *succ; 
}; 

typedef elem * node; 


node tail(node nodo) {
  return nodo->succ;
}

node previous(node nodo) {
  return nodo->prev;
}

char* head(node nodo) {
  return nodo->URL;
}


ostream& printNode(node node, ostream& stream) {
  stream 
    << "Informazione della lista: " << head(node) 
    << "\t Indirizzo: " << node;

  return stream;
}



node urlSearch(node nodi, char *urlToSearch) {
  while (nodi != NULL) {
    if (strcmp(head(nodi), urlToSearch) == 0) {
      return nodi;
    }
    else {
      nodi = tail(nodi);
    } 
  }  

  cout << "Sono la funzione *search*.\nNon ho trovato il valore all'interno della lista.";
  return NULL; 
} 

node nodeDelete (node nodi, node nodeToDelete) {
  cout << "Sono la funzione *nodeDelete*. Ho ricevuto in ingresso la testa della lista, e il nodo con indirizzo " << nodeToDelete << " e con URL " << head(nodeToDelete) << endl; 
  cout << "Procedo con l'eliminazione dell'elemento..." << endl; 

  // Se uno dei due è null
  // esco sbattendomene i coglioni
  if (nodi == NULL || nodeToDelete == NULL)
    return nodi;

  node next = tail(nodeToDelete);
  node prev = previous(nodeToDelete);

  /**
   * Linko i due nodi che 
   * hanno in mezzo `nodeToDelete`,
   * se esistono
   * 
   * prima:
   *  prev <-> nodeToDelete <-> next
   * 
   * elimino nodeToDelete: 
   *  prev <-> n̶o̶d̶e̶T̶o̶D̶e̶l̶e̶t̶e̶ <-> next
   * 
   * risultato:
   *  prev <-> next
   * 
   * se next è null:
   *  prev.next = NULL; prev -> NULL
   * 
   * se prev è null:
   *  next.prev = NULL; NULL <- next
   */
  if (next != NULL) next->prev = prev;
  if (prev != NULL) prev->succ = next;

  if (nodi == nodeToDelete)
    nodi = next;

  delete nodeToDelete; 
  cout << "Eliminazione avvenuta" << endl;
  return nodi; 
}


node urlDelete (node nodi, char* url) {
  node indirizzoDelete = urlSearch(nodi, url); 

  if (indirizzoDelete != NULL) {
    nodi = nodeDelete(nodi, indirizzoDelete);
  }
  else {
    errore("Non ho trovato nessun nodo con l'url indicato"); 
  }

  return nodi; 
}

void printList (node nodi, ostream &flusso) {
  flusso << "Stampa della lista..." << endl; 

  while (nodi != NULL) {
    printNode(nodi, cout) << endl;
    nodi = tail(nodi);
  }

  flusso << "Stampa della lista terminata" << endl; 
}


node insertElem(node testa, node nodo) {
  nodo->succ = testa;
  nodo->prev = NULL;
  
  if (testa != NULL) 
    testa->prev = nodo; 

  return nodo;
}

node newList (int dimensione) {
  node testa = NULL;

  for (int i=1; i<=dimensione; i++) {
    node nodo = new elem{};

    cout << "Digita l'URL del nuovo nodo> ";
    cin >> nodo->URL; 
    testa = insertElem(testa, nodo);
  }

  return testa; 
}

int main () {
  const char menu [] = 
    "Digita 1-> Inizializzare la lista di URL\n"
    "Digita 2-> Cancellare un URL dalla lista\n"
    "Digita 3-> Stampare la cronologia\n"
    "Digita 4-> Salvare la lista di URL su un file di testo .txt\n"
    "Digita 5-> Cercare un URL nella lista\n"
    "Digita 0-> Uscire dal programma\n"
    " >> ";
  
  int scelta; 
  node testa = NULL; 

  while (true) {
    cout << menu; 
    cin >> scelta; 

    switch (scelta) {
      case 1: {  
        int n; 
        do {
          cout << "Quanti URL devo allocare? ";
          cin >> n;
        } 
        while (n <= 0); 

        testa = newList(n);
        cout << "Allocazione della lista conclusa con successo." << endl; 

        break; 
      }
      case 2: {
        char urlCancel[dimensioneURL]; 
        cout << "Cosa devo cancellare? "; 
        cin >> urlCancel; 
        testa = urlDelete(testa, urlCancel); 

        break;
      }
      case 3: {
        if (testa==NULL) {
          errore("La lista sembra vuota.");
        } 
        else {
          printList(testa, cout);
        } 

        break; 
      }
      case 4:{
        ofstream ESPORTA("cronologia.txt");
        if (testa == NULL) {
          errore("La lista sembra vuota.");
        } 
        else {
          printList(testa, ESPORTA);
        }
      
        break; 
      }
      case 5: {          
        char urlRicerca [dimensioneURL]; 
        cout<<"Cosa devo cercare? "; cin>>urlRicerca; 
        node addressSearch = urlSearch(testa, urlRicerca); 

        if (addressSearch != NULL) {
          cout<<"L'elemento "<< urlRicerca << " si trova nella lista e ha indirizzo " << addressSearch << endl;
        }
        else {
          errore("L'elemento non è stato trovato"); 
        }

        break; 
      }

      case 0:
        cout<<"CIAO! ALLA PROSSIMA ESECUZIONE"<<endl; 
        return 0;
    }

    cout << "\n\n";
  }

  errore("");
  return 0; 
}