#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

long long pow(int base, int exp) {
    long long result = 1;
    while (exp-- > 0)
        result *= base;

    return result;
}


void strAdd(char *orig, int& at, char c) {
    orig[at++] = c;
}


char *intToString(long long num) {
    int i = 0;
    for (; num >= pow(10, i); i++)
        ;

    int currentIndex = 0;
    char *result = new char[i + 2];
    result[i + 1] = '\0';

    char sign = num >= 0
        ? '+'
        : '-';

    strAdd(result, currentIndex, sign);

    i -= 1;
    for (; i >= 0; i--) {
        int current = num / pow(10, i);
        char toAdd = current + '0';

        strAdd(result, currentIndex, toAdd);
        num %= pow(10, i);
    }

    return result;
}


int main()
{
    char *str = intToString(16217);
    cout << str;
}