#include "search_algos.h"
#include <math.h>

/**
 * jump_search - searches for a value in an array of integers using the Jump
 * search algorithm
 * @array: pointer to the first element of the array
 * @size: the number of elements in the array
 * @value: the value to search for
 *
 * Return: the index where the value is located, or -1 if it is not found
 */
int jump_search(int *array, size_t size, int value)
{
	int jump, prev, end;

	if (!array || size == 0)
		return (-1);

	jump = sqrt(size);
	prev = 0;
	end = jump;

	while (end < (int)size && array[end] < value)
	{
		printf("Value checked array[%d] = [%d]\n", end, array[end]);
		prev = end;
		end += jump;
	}

	printf("Value found between indexes [%d] and [%d]\n", prev, end);

	end = (end >= (int)size) ? (int)size - 1 : end;

	for (; prev <= end; prev++)
	{
		printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
		if (array[prev] == value)
			return (prev);
	}

	return (-1);
}

