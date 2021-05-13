// ES. 2

// Traccia: Scrivere un programma che legga da tastiera un numero naturale n e,
// 	 se n e' dispari, stampi 1, altrimenti stampi 0. 

// Un possibile output su schermo e' il seguente:

// Immettere il numero n: 7
// Risultato: 1
#include <iostream>

int main() {
  uint n;
  std::cout << "number: ";
  std::cin >> n;

  std::cout << (n % 2);
}