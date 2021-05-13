#include <stdio.h>
#include <math.h>
#include <stdbool.h>

const double G = 6.67259e-11;

bool arePositive(double m1, double m2, double d) {
    return 
        m1 >= 0 ||
        m2 >= 0 ||
        d >= 0;
}

extern double newton(double m1, double m2, double d) {
    if (!arePositive(m1, m2, d))
        return -1;

    return m1 * m2 * G / pow(d, 2);
}


int main()
{
    printf("%e\n", newton(10, 20, 4));
}