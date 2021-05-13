#include <iostream>


uint fib(uint n) {
  if (n == 0 || n == 1)
    return n;

  return fib(n - 1) + fib(n - 2);
}


int main() {
  int n;
  do {
    std::cout << "n: ";
    std::cin >> n;
  }
  while (n < 0);

  std::cout << fib(n) << std::endl;
}