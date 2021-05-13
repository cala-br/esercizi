// ES. 6

// Traccia: Scrivere un programma che legga da tastiera due numeri naturali i e j,
// e stampi il valore di un numero naturale che ha la seguente rappresentazione 
// binaria: 
// le j cifre piu' significative di tale numero (ossia quelle a partire dalla
// cifra piu' a sinistra) coincidono con le j cifre meno significative 
// (ossia quelle a partire dalla cifra piu' a destra) della rappresentazione 
// binaria di i, mentre le restanti cifre sono a zero.

// Esempio. Supponiamo che n abbia la seguente rappresentazione binaria:
// 00000000 00000000 00000000 01011001 (supponendo che i numeri naturali
// siano rappresentati su 32 bit).
// Se j=4, allora il numero calcolato avra' la seguente rappresentazione
// binaria: 10010000 00000000 00000000 00000000.

// Un possibile output su schermo e' il seguente:

// Immettere il numero i: 5
// Immettere il numero j: 7
// Risultato: 167772160
#include <iostream>

int main() {
  uint i, j;
  std::cout << "i, j: ";
  std::cin >> i >> j;

  uint bitsToShift = sizeof(i) * 8 - j;
  uint z = i << bitsToShift;
  std::cout << z;
}