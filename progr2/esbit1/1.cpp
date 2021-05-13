// ES. 1
// Traccia: Scrivere un programma che legga da tastiera un numero naturale n,
// moltiplichi il numero per 2 senza utilizzare l'operatore di moltiplicazione
// e stampi il risultato sullo schermo.
// Trascurare eventuali problemi di overflow.

// Un possibile output e' il seguente:

// Immettere il numero n: 3
// n * 2 = 6
#include <iostream>

int main() {
  uint n;
  std::cout << "n: ";
  std::cin >> n;

  n <<= 1;
  std::cout << n;
}