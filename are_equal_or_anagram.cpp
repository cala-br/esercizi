#include <iostream>

using namespace std;


int alignIndex(char c) {
    if (c > 'A' && c < 'Z')
        return c - 'A';

    if (c > 'a' && c < 'z')
        return c - 'a';

    return -1;
}


bool areEqualOrAnagram(
    const char *first, 
    const char *second
) {
    const int vowelsCount = ('z' - 'a') + ('Z' - 'A');
    int vowels[vowelsCount] = {};

    bool areEqual = true;
    for (int i = 0; first[i] || second[i]; i++) 
    {
        bool areLengthsDifferent = 
            first[i] && !second[i] ||
            !first[i] && second[i];

        if (areLengthsDifferent)
            return false;

        if (first[i] != second[i])
            areEqual = false;
        
        vowels[alignIndex(first[i])]--;
        vowels[alignIndex(second[i])]++;
    }

    if (areEqual)
        return true;

    for (int i = 0; i < vowelsCount; i++) {
        if (vowels[i] != 0)
            return false;
    }

    return true;
}


bool areEqualOrAnagram_2(
    const char *first, 
    const char *second
) {
    const int vowelsCount = ('z' - 'a') * 2;
    int vowels[vowelsCount] = {};

    for (int i = 0; first[i]; i++) 
    {
        if (!second[i])
            return false;

        char current = alignIndex(first[i]);
        vowels[current]--;
    }

    for (int i = 0; second[i]; i++)
    {
        if (!first[i])
            return false;

        char current = alignIndex(second[i]);
        int& currentCount = vowels[current];
        
        currentCount += 1;
        if (currentCount > 0)
            return false;
    }

    return true;
}


bool areEqualOrAnagram_3(
    const char *first, 
    const char *second
) {
    int result = 0;

    for (int i = 0; first[i] || second[i]; i++) 
    {
        bool areLengthsDifferent = 
            first[i] && !second[i] ||
            !first[i] && second[i];

        if (areLengthsDifferent)
            return false;
        
        result = first[i] - second[i];
    }

    return result == 0;
}


int main()
{
    cout
        << areEqualOrAnagram("nadia", "diana") << '\n'
        << areEqualOrAnagram("nadia", "nadia") << '\n'
        << areEqualOrAnagram("nadia", "diana") << '\n'
        << areEqualOrAnagram("nadia", "luca") << '\n'
        << areEqualOrAnagram("luca", "paolo") << '\n'
        << areEqualOrAnagram("nadia", "paolo") << '\n'
        << areEqualOrAnagram("aaccv", "aaoib") << '\n';
}