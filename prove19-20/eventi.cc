#include <iostream>
#include <cstdlib>
#include <time.h>


int gen(double probability)
{
    if (probability == 0)
        return 0;

    if (probability == 100)
        return 1;

    double num = rand() % 100 + 1;
    return num > probability
        ? 0
        : 1;
}


int main()
{
    int oneCount = 0;
    int zeroCount = 0;

    for (int i = 0; i < 100000; i++) {
        int res = gen(10);
        if (res == 1)
            oneCount++;

        else zeroCount++;
    }

    std::cout << oneCount / 1000. << "%, " << zeroCount / 1000. << '%' << std::endl;
}