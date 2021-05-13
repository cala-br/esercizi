#include <iostream>

int fact(int a) {
    int sum = 1;
    while (a) 
        sum *= a--;
}

int main()
{
    std::cout << fact(5);
}