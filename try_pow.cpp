#include <iostream>

using namespace std;


bool tryMultiply(double a, double b, double& result) {
    result = a * b;

    if (a == 0)
        return true;

    bool didOverflow = result / a != b; 
    if (didOverflow)
        return false;
}



bool tryPow(double base, int exponent, double& result) {
    result = 1;
    while (exponent-- > 0) {
        bool hadNoOverflow =
            tryMultiply(result, base, result);

        if(!hadNoOverflow)
            return false;
    }
    return true;
}


int main() 
{
    double result;
    bool ok = tryPow(-5, 20, result);

    if (!ok)
        cout << "Error\n";
    else 
        cout << result << '\n';
}