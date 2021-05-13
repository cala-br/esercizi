// ES. 10 

// Traccia: Scrivere un programma che legga da tastiera un numero
// naturale n, calcoli il piu' grande numero naturale pari i, tale che
// i<=n, e stampi il risultato sullo schermo  (ovviamente, se n e' pari
// i sara' uguale ad n, mentre, se n e' dispari, i sara' uguale a n-1).
// Suggerimento: lavorare sulla configurazione di bit che rappresenta n.

// Un possibile output su schermo e' il seguente:

// Immettere il numero n: 7867
// Risultato: 7866
#include <iostream>

int main() {
  uint n;
  std::cout << "n: ";
  std::cin >> n;

  uint i = n & ~1;
  std::cout << i;
}