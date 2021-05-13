#include <iostream>

using namespace std;


void getUniques(char *source)
{
    const int lettersCount = 'z' - 'a';
    int letters[lettersCount] = {};

    for (int i = 0; source[i]; i++)
    {
        char current = source[i];
        letters[current - 'a']++;
    }

    int j = 0;
    for (int i = 0; i < lettersCount; i++)
    {
        if (letters[i] == 1)
            source[j++] = i + 'a'; 
    }

    source[j] = '\0'; 
}


int main() 
{
    char str[] = "rinoceronte";

    getUniques(str);
    cout << str;
}