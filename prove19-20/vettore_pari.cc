/* Esercizio:
 * Scrivere una funzione:
 * 
 * int init (int vett[], int vett2[], int n);
 * 
 * che riceve in ingresso due vettori di interi di uguale dimensione e un intero
 * n pari alla dimensione dei due vettori, inizializza il secondo vettore con i 
 * soli interi PARI (contenuti nel vettore di partenza) 
 * e ritorna il numero di elementi significativi contenuti nel nuovo vettore.
 * Se il numero di interi PARI contenuti nel primo vettore e' minore di
 * n, la funzione assegna agli elementi nelle posizioni 'vuote' del secondo 
 * vettore il valore -1.
 * Ad esempio, se il primo vettore in ingresso ha dimensione 5 e contiene i valori
 * [3, 2, 7, 8, 10], la funzione assegna agli elementi del secondo vettore i 
 * valori:
 * [2, 8, 10, -1, -1].
 * 
 * Si scriva poi un main() che compie le seguenti azioni:
 * a) definisce ed inizializza una costante n;
 * b) definisce due vettori di interi di dimensione n;
 * c) chiede all'utente di inserire i valori da inserire nel primo vettore
 * c) richiama la funzione init() passandole i due vettori;
 * d) stampa solo i numeri validi contenuti nel secondo vettore (quello contenente
 *    i numeri pari).
 */

#include <iostream>

using namespace std;


bool isEven(int value) {
    return value % 2 == 0;
}

int init(const int vect[], int vect2[], const int length)
{
    int j = 0;
    for (int i = 0; i < length; i++) 
    {
        if (isEven(vect[i])) {
            vect2[j++] = vect[i];
        }
    }

    for (int i = j; i < length; i++)
        vect2[i] = -1;

    return j;
}


int main()
{
    const int n = 5;
    int v1[n];
    int v2[n];

    cout << "Inserire i valori del primo vettore [" << n << "]" << endl;
    for (int i = 0; i < n; i++) 
        cin >> v1[i];
    
    const int evensCount = init(v1, v2, n);
    
    cout << "Numeri pari:" << endl;
    for (int i = 0; i < evensCount; i++)
        cout << v2[i] << ' ';

    cout << endl;
    return 0;
}