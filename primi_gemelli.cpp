#include <iostream>
#include <cmath>


int main()
{
    const int TARGET_DIFFERENCE = 2;

    int a;
    int b;
    std::cout << "Insert two numbers: ";
    std::cin >> a;
    std::cin >> b;

    if (a < 1 or b < 1) return 1;
    if (a == b) return 1;

    const int difference = abs(b - a);
    if (difference != TARGET_DIFFERENCE)
        return 1;
    
    const bool areBetween1And3 = 
        a >= 1 and a <= 3 and
        b >= 1 and b <= 3;

    if (areBetween1And3) {
        std::cout << "\nThe numbers are twin primes" << std::endl;
        return 0;
    }


    const bool areMultiplesOfTwo =
        (a % 2 == 0 and a != 2) or
        (b % 2 == 0 and b != 2);

    if (areMultiplesOfTwo) return 1;


    const int maxA = static_cast<int>(sqrt(a));
    const int maxB = static_cast<int>(sqrt(b));
    
    int maxDivider;
    if (maxA > maxB) maxDivider = maxA;
    else maxDivider = maxB;

    for (int i = 3; i <= maxDivider; i += 2) {
        const bool anyDivisible = 
            a % i == 0 or b % i == 0;

        if (anyDivisible) return 1;
    }
    
    std::cout << "\nThe numbers are twin primes" << std::endl;
}