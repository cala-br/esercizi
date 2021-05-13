// Scrivere una funzione che, dato un vettore in ingresso, e 
// senza utilizzare variabili di appoggio in cui memorizzare 
// temporaneamente valori degli elementi del vettore, stampi il
// numero di occorrenze di ciascun elemento del vettore.
//
// Supporre che la funzione abbia la possibilità di modificare il vettore a piacimento.
#include <iostream>

using namespace std;


void printOccurrencies(const int array[], const int length)
{
    for (int i = 0; i < length; i++)
    {
        int currentOccurrencies = 0;
        bool wasAlreadyScanned = false;

        for (int j = 0; j < length; j++)
        {
            const bool doElementsMatch = 
                array[i] == array[j];

            if (doElementsMatch) {
                if (j < i) {
                    wasAlreadyScanned = true;
                    break;
                }

                currentOccurrencies++;
            }
        }

        if (!wasAlreadyScanned) {
            cout << array[i] << ": " << currentOccurrencies << endl;
        }
    }
}


int main()
{
    int arr[] = {2, 2, 5, 2, 5};
    int length = sizeof(arr) / sizeof(*arr);

    printOccurrencies(arr, length);
}