#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>


bool isPunctuation(char c) {
    return c < 'a' || c > 'z';
}

bool shouldMask(char letter, const char *validLetters) {
    while (*validLetters) {
        if (letter == *validLetters++) {
            return false;
        }
    }

    return true;
}

extern char *hangman(const char *sentence, const char *letters) {
    if (sentence == NULL || letters == NULL)
        return NULL;

    const int len = strlen(sentence);
    char *result = (char*)calloc(len + 1, sizeof(char));
    if (!result)
        return NULL;

    char *tmp = result;
    char c;
    while (c = *sentence++) {
        c = tolower(c);
        if (isPunctuation(c)) {
            *tmp++ = c;
            continue;
        }
        
        *tmp++ = shouldMask(c, letters)
            ? '*'
            : c;
    }

    return result;
}


int main()
{
    char *str = hangman("Il gioco dell'impiccato non e' case-sensitive", "aeiou");
    puts(str);
}