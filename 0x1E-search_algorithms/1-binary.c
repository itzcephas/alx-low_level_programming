#include "search_algos.h"

int recursive_search(int *array, size_t size, int value)
{
    size_t i, half;

    if (!array || !size)
        return (-1);

    half = (size - 1) / 2;
    printf("Searching in array: %d", array[0]);
    for (i = 1; i < size; i++)
        printf(", %d", array[i]);
    printf("\n");

    if (array[half] == value)
        return ((int)half);
    else if (array[half] > value)
        return (recursive_search(array, half, value));
    else
    {
        int right = recursive_search(array + half + 1, size - half - 1, value);
        return (right == -1 ? -1 : right + half + 1);
    }
}

int binary_search(int *array, size_t size, int value)
{
    if (!array)
        return (-1);
    return (recursive_search(array, size, value));
}

