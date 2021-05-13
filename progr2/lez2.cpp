#include <iostream>


long mask(int position) {
  return (1 << position);
}

bool isSet(long number, int position) {
  return number & mask(position);
}

void setBit(long& number, int position) {
  number |= mask(position);
}

void resetBit(long& number, int position) {
  number &= ~mask(position);
}

void flip(long& number, int position) {
  number ^= mask(position);
}


int main() {
  long number;
  long position;
  std::cout << "number, position: ";
  std::cin >> number >> position;

  setBit(number, position);
  std::cout << number;
}