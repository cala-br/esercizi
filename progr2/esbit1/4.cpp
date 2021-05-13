// ES. 4

// Traccia: Scrivere un programma che legga da tastiera due numeri
// naturali n ed i, effettui la divisione intera del numero n per 2^i
// senza utilizzare l'operatore divisione, e stampi il risultato sullo
// schermo.

// Un possibile output su schermo e' il seguente:

// Immettere il numero n: 12
// Immettere il numero i: 2
// 12 / (2^2) = 3
#include <iostream>

int main() {
  uint n, i;
  std::cout << "n, i: ";
  std::cin >> n >> i;

  uint result = n >> i;
  std::cout << result;
}