#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "es5.h"


int getFileLength(FILE *file) {
    fseek(file, 0, SEEK_END);
    const int fileLen = ftell(file);
    fseek(file, 0, SEEK_SET);

    return fileLen + 1;
}


void readNext(FILE *in, char *buffer) {
    fseek(in, +3, SEEK_CUR);
    fread(buffer, sizeof(char), 2, in);
    fseek(in, -5, SEEK_CUR);
    fread(buffer + 2, sizeof(char), 2, in);
    fseek(in, +4, SEEK_CUR);
}


Dvec *readDvecFrom(const char *path) {
    Dvec *result = (Dvec*)calloc(1, sizeof(Dvec));
    if (!result)
        return NULL;

    FILE *in = fopen(path, "rb");
    if (!in) 
        return result;

    const int bytesPerChunk = 4;
    char buffer[bytesPerChunk];

    const int fileLength = getFileLength(in);
    if (fileLength < 5)
        return result;
    
    const int valuesCount = fileLength / 6;
    const double divider = pow(2, 14); 
    result->length = valuesCount;
    result->values = 
        (double*)calloc(valuesCount, sizeof(double));

    int current = 0;
    while (ftell(in) < fileLength) {
        readNext(in, buffer);
        result->values[current++] = 
            (double)(int16_t)strtol(buffer, NULL, 16) / divider;
    }

    fclose(in);
    return result;
}


int main()
{
    Dvec *dvec = readDvecFrom("testdvec");

    for (int i = 0; i < dvec->length; i++) {
        printf("%f\n", dvec->values[i]);
    }
}