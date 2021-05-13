#include <iostream>

using namespace std;

struct Pair {
    int key;
    int count;
};

int findPair(const Pair *pairs, int key, int length) {
    for (int i = 0; i < length; i++) {
        if (pairs[i].key == key) {
            return i;
        }
    }

    return -1;
}

Pair *countDuplicates(const int *arr, int& length)
{
    Pair *result = new Pair[length];

    int j = 0;
    for (int i = 0; i < length; i++) {
        int key = arr[i];
        int pairIndex = findPair(result, key, length);

        if (pairIndex == -1) {
            result[j++] = {key, 1};
            continue;
        }

        result[pairIndex].count++;
    }

    length = j;
    return result;
}


int main()
{
    int arr[] = {3, 4, 4, 4, 6, 10, 10};
    int len = sizeof(arr) / sizeof(*arr);

    Pair *dups = countDuplicates(arr, len);

    for (int i = 0; i < len; i++) {
        cout << dups[i].key << ':' << dups[i].count << '\n';
    }
}