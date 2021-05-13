#include <iostream>
using namespace std;


bool tryGetMaxSubsequence(int *numbers, int& length, int startingIndex)
{
    if (startingIndex >= length) {
        return false;
    }

    int i = startingIndex + 1;
    int j = 0;
    int last = numbers[startingIndex];

    for (; i < length; i++) {
        numbers[j++] = last;
        
        int current = numbers[i];
        if (current < last)
            break;
            
        last = current;
    }

    length = i - startingIndex;
    return true;
}


int main()
{
    int nums[] = {2, 3, 5, 10, 9, 12};
    int length = sizeof(nums) / sizeof(*nums);

    if (!tryGetMaxSubsequence(nums, length, 1)) {
        cout << "errore";
        return -1;
    }

    for (int i = 0; i < length; i++)
        cout << nums[i] << '\n';
}