#include <iostream>

using namespace std;


int& getCountAt(int *letters, char c) {
    return letters[c - 'a'];
}


char *getStringWithDuplicates(const char *source) {
    const int lettersCount = 'z' - 'a';
    int letters[lettersCount] = {};

    int strLen = 0;
    for(int i = 0; source[i]; i++) {
        char currentChar = source[i];
        int& count = getCountAt(letters, currentChar);
        count++;

        if (count == 2)
            strLen += 2;

        if (count > 2)
            strLen++;
    }

    char *result = new char[strLen + 1];
    int j = 0;
    
    for (int i = 0; source[i]; i++) {
        char currentChar = source[i];
        int letterCount = getCountAt(letters, currentChar);

        if (letterCount < 2)
            continue;

        result[j++] = currentChar;
    }

    result[strLen] = '\0';

    return result;
}

int main()
{
    char *res = getStringWithDuplicates("esose");
    cout << res;
}