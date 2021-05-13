#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef enum Direction {
    FORWARDS,
    BACKWARDS,
} Direction;


bool isIndexInRange(int index, int min, int max, Direction direction) {
    return direction == FORWARDS
        ? index >= min && index <= max
        : index >= max && index <= min;
}

void swap(int *start, int *end) {
    *start ^= *end ^= *start ^= *end;
}

void swap(size_t *a, size_t *b) {
    *a ^= *b ^= *a ^= *b;
}


extern int *slice(
    const int *vect, 
    size_t *length, 
    size_t start, 
    size_t end, 
    int step
) {
    const int len = *length;
    const Direction direction = step >= 0
        ? FORWARDS
        : BACKWARDS;

    if (direction == BACKWARDS)
        swap(&start, &end);
    
    int *result = (int*)calloc(len, sizeof(int));
    if (!result)
        return NULL;

    int count = 0;
    int i = start;
    for (; isIndexInRange(i, start, end, direction); i += step) {
        result[count++] = vect[i];
    }

    *length = count;
    return result;
}


void printArr(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main()
{
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8};
    size_t len = sizeof(v) / sizeof(*v);

    int *res = slice(v, &len, 2, 6, 1);

    printArr(res, len);
}