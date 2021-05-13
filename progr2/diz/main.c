#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DICTIONARY_LENGTH 30
#define MAX_LINE_LENGTH 200
#define MAX_WORD_LENGTH 20

struct DictionaryEntry {
  char word[MAX_WORD_LENGTH];
  char encoding[MAX_WORD_LENGTH];
};

typedef struct DictionaryEntry DictionaryEntry;
typedef DictionaryEntry Dictionary[MAX_DICTIONARY_LENGTH];
typedef char Line[MAX_LINE_LENGTH];


FILE *tryOpen(const char *path, const char *modes);
void cleanup(FILE *input, FILE *dictionary, FILE *output);
void maybeClose(FILE *file);
int fillDictionary(Dictionary dict, FILE *dictionaryFile);
void replaceTokens(Line input, Dictionary dict, int dictionaryLength);
int copyUntil(char *destination, const char *source, const char *stop);


int main() {
  FILE *inputFile = tryOpen("input.txt", "r");
  FILE *dictionaryFile = tryOpen("dictionary.txt", "r");
  FILE *outputFile = tryOpen("ricodificato.txt", "w");

  if (!inputFile || !dictionaryFile || !outputFile) {
    cleanup(inputFile, dictionaryFile, outputFile);
    return EXIT_FAILURE;
  }

  Dictionary dictionary;
  Line line;
  int dictionaryLength = 
    fillDictionary(dictionary, dictionaryFile);

  while (!feof(inputFile)) {
    fgets(line, MAX_LINE_LENGTH, inputFile);
    replaceTokens(line, dictionary, dictionaryLength);
    fprintf(outputFile,"%s", line);
  }

  cleanup(inputFile, dictionaryFile, outputFile);
}


void cleanup(FILE *input, FILE *dictionary, FILE *output) {
  maybeClose(input);
  maybeClose(dictionary);
  maybeClose(output);
}


FILE *tryOpen(const char *path, const char *modes) {
  FILE *result = fopen(path, modes);
  if (!result) {
    printf("Error opening %s\n", path);
    return NULL;
  }
  return result;
}

void maybeClose(FILE *file) {
  if (file)
    fclose(file);
}


int fillDictionary(Dictionary dict, FILE *dictionaryFile) {
  int dictionaryLength;
  fscanf(dictionaryFile, "%d", &dictionaryLength);

  for(int i = 0; i < dictionaryLength; i++) {
    fscanf(dictionaryFile, "%s%s", dict[i].encoding, dict[i].word);
  }
  return dictionaryLength;
}


void replaceTokens(Line input, Dictionary dictionary, int dictionaryLength) {
  Line result;
  
  for (int i = 0; i < dictionaryLength; i++) {
    DictionaryEntry *entry = &dictionary[i];

    char *pos = strstr(input, entry->word);
    if (pos == NULL)
      continue;

    int oldLen = strnlen(entry->word, MAX_WORD_LENGTH);
    int newLen = strnlen(entry->encoding, MAX_WORD_LENGTH);

    int offset = copyUntil(result, input, pos);
    strncpy(result + offset, entry->encoding, MAX_WORD_LENGTH);
    strcpy(result + offset + newLen, input + offset + oldLen);

    strcpy(input, result);
  }
}


int copyUntil(
  char *destination, 
  const char *source, 
  const char *stop
) {
  int i = 0;
  for(; source + i != stop; i++)
    destination[i] = source[i];

  return i;
}