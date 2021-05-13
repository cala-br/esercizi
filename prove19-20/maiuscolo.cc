/**
 * Definire una funzione che prenda in ingresso (parametro formale) un
 * oggetto di tipo carattere e, se si tratta di un carattere maiuscolo, lo
 * trasformi nel corrispondente carattere minuscolo. La funzione deve ritornare
 * vero se la conversione è avvenuta, falso altrimenti.
 * Scrivere quindi un main in cui si utilizzi tale funzione.
 */
#include <iostream>

using namespace std;

bool toLower(char& maybeUpper)
{
    const bool isNotUpper = 
        maybeUpper < 'A' && maybeUpper > 'Z';

    if (isNotUpper)
        return false;
    
    maybeUpper = maybeUpper - 'A' + 'a';
    return true;
}


int main()
{
    char c = 'Z';
    toLower(c);
    cout << c;
}