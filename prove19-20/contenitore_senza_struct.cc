/*
 * Contenitore
 * 
 * Un Contenitore e' in grado di contenere elementi in numero limitato (la
 * capienza del contenitore). Ciascun elemento ha un nome che consiste in
 * una lettera (minuscola) dell'alfabeto. Piu' elementi di un contenitore
 * possono avere lo stesso nome. Le operazioni che possono essere effettuate
 * sul contenitore sono le seguenti:
 * 
 * .	Inizializza(N);
 * Inizializza il contenitore con capienza pari ad N elementi. Il
 * contenitore e' vuoto. L'eventuale contenuto precedente viene perso.
 * 
 * .	Inserisci(p)
 * Inserisce un elemento avente nome p.
 * 
 * .	Estrai(p)
 * Estrae dal contenitore tutti gli elementi aventi nome p.
 * 
 * .	Modifica(N)
 * Modifica la capienza del contenitore. Dopo la modifica il contenitore
 * ha capienza N e contenuto identico a quello originario. Affinche'
 * l'operazione abbia successo, il numero di elementi contenuti nel
 * contenitore deve essere minore od uguale ad N.
 * 
 * .	capienza()
 * Ritorna la capienza del contenitore.
 * 
 * .	quanti()
 * Ritorna il numero degli elementi presenti nel contenitore.
 * 
 * .	stampa()  
 * 
 * Stampa il contenuto del Contenitore. LŽ¢uscita ha la forma seguente:
 * 		<a:3, d:1, s:5>
 * In questo esempio, nel contenitore sono presenti tre elementi di nome
 * 'a', uno di nome 'd' e cinque di nome 's'.
 * 
 * 
 * Gestire opportunamente le condizioni di errore, tranne i problemi di
 * overflow e le condizioni di errore in lettura da stdin.
 * 
 * Nella soluzione e' contenuto anche un main, che potete eventualmente
 * utilizzare per testare le funzioni nella vostra soluzione. Svolgere
 * l'esercizio senza utilizzare il costrutto struct (non ancora visto a
 * lezione).
 */
#include <iostream>

using namespace std;

enum ContainerError {
    NONE = 0,
    BAD_KEY = -1,
    CONTAINER_FULL = -2,
};


const int MAX_LENGTH = 'z' - 'a' + 1;

int _container[MAX_LENGTH] = {};
int _capacity = MAX_LENGTH;
int _elementsCount = 0;


int capacity() {
    return _capacity;
}

int elementsCount() {
    return _elementsCount;
}


int tryAlignKey(const char key) {
    if (key < 'a' || key > 'z')
        return BAD_KEY;

    return key - 'a';
}


bool tryUpdateCapacity(const int newCapacity) {
    if (newCapacity > MAX_LENGTH || newCapacity <= 0)
        return false;

    _capacity = newCapacity;
    return true;
}


bool init(const int capacity) {
    const bool updated = 
        tryUpdateCapacity(capacity);

    if (!updated)
        return false;

    _elementsCount = 0;
    for (int i = 0; i < MAX_LENGTH; i++) 
        _container[i] = 0;

    return true;
}


int tryInsert(const char key) {
    const int index = tryAlignKey(key);

    if (index == BAD_KEY)
        return BAD_KEY;

    _elementsCount++;
    _container[index]++;
    return NONE;
}


int tryExtract(const char key) {
    const int index = tryAlignKey(key);

    if (index == BAD_KEY)
        return BAD_KEY; 

    int result = _container[index];
    
    _elementsCount++;
    _container[index] = 0;
    return result;
}


void dump(ostream&stream, const int index) {
    const char key = 'a' + index;
    stream << key << ':' << _container[index];
}


void dump(ostream& stream) {
    bool isFirst = true;

    stream << '<';
    for (int i = 0; i < _capacity; i++) {
        if (_container[i] == 0)
            continue;

        if (!isFirst)
            stream << ", ";

        dump(stream, i);
        isFirst = false;
    }
    stream << '>' << endl;
}


void testRemove(const char key, const int expected)
{
    const int value = tryExtract(key);
    if (value == BAD_KEY)
        cerr << "Bad key";
    else if (value == expected)
        cout << "Ok";
    else
        cout << "Error: " << value;

    cout << '\n';
}


int main()
{
    init(5);
    tryInsert('a');
    tryInsert('b');
    tryInsert('b');
    tryInsert('d');

    testRemove('a', 1);
    testRemove('b', 2);
    testRemove('d', 3);
    testRemove(0, 0);

    dump(cout);
}
