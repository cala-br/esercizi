#include <iostream>

typedef bool(*Predicate)(int);

bool isEven(int num) {
    return num % 2 == 0;
}


int main() {
    Predicate p = isEven;

    std::cout << "Is even: " << p(10);
}