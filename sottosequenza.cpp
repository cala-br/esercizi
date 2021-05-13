#include <iostream>

void removeAdjacents(int *numbers, int& length, int startingIndex)
{
    if (startingIndex >= length)
        return;

    int i = startingIndex;
    int last = numbers[i];
    int removedElements = 1;
    for (; i < length - 1; i++)
    {
        int current = numbers[i + 1];
        if (current < last)
            break;

        last = current;
        removedElements++;
    }

    i++;
    int j = startingIndex;
    for (; i < length; i++, j++) {
        numbers[j] = numbers[i];
    }

    length -= removedElements;
}


int main()
{
    int nums[] = {2, 1, 5, 10, 9, 12};
    int len = sizeof(nums) / sizeof(*nums);

    removeAdjacents(nums, len, 1);

    for (int i = 0; i < len; i++)
        std::cout << nums[i] << '\n';
}