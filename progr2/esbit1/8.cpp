// ES. 8

// Traccia: Scrivere un programma che legga da tastiera due numeri naturali k e j,
// e ruoti a sinistra di j posizioni la rappresentazione binaria del numero k.
// -> La rotazione a sinistra di j posizioni di una configurazione di bit si 
// comporta come la traslazione (shift) a sinistra di j posizioni, 
// eccetto il fatto che, i j bit piu' significativi di tale configurazione 
// divengono i j bit meno significativi della nuova configurazione (mentre, nel 
// caso della traslazione i j bit piu' significativi sarebbero stati buttati via).

// -> Attenzione sempre al caso j > 31 e notare che anche in questo
// esercizio, dobbiamo scrivere il programma in maniera tale che funzioni
// bene nel caso j=0.

// Un possibile output su schermo e' il seguente:

// Rotazione a sinistra:
// Immettere il numero k: 2147483648 (2^31)
// Immettere il numero j: 1
// Risultato: 1
#include <iostream>

int main() {
  uint k, j;
  std::cout << "k, j: ";
  std::cin >> k >> j;

  const uint bitsInK = sizeof(k) * 8;
  const uint bitsToShift = bitsInK - j;
  const uint left = k << bitsToShift;
  const uint right = k >> bitsToShift;
  const uint result = right | left;

  std::cout << result;
}