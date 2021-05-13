#include <iostream>
#include <cmath>


void printBase2(int base10Num)
{
    unsigned long base2Num = pow(2, 31);
    int quartet = 0;
    
    while (base2Num > 0) 
    {
        const int maybeMultipleOf2 = 
            base10Num / base2Num;

        std::cout << maybeMultipleOf2 % 2;
        base2Num /= 2;

        const bool printSpace = 
            (++quartet %= 4) == 0;

        if (printSpace)
            std::cout << ' ';
    }

    std::cout << std::endl;
}


int main()
{
    printBase2(37127634);
}