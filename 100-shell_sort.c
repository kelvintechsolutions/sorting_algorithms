#include "sort.h"
/**
 * swap_bubble -it functions to swap/sort.
 *@a: to be swapped.
 *@b: to be swapped.
 * Return:it  Always  returns 0.
 */
void swap_bubble(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort -it sorts array with shell sort algorithm.
 *@array:it is the array to be sorted.
 *@size:it is the size of array.
 * Return:t returns  Always 0
 */
void shell_sort(int *array, size_t size)
{
	size_t gap;
	size_t i, j;

	if (array == NULL || size < 2)
		return;
	for (gap = 1; gap <= (size / 3);)
		gap = gap * 3 + 1;
	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; ++i)
		{
			for (j = i; j >= gap && array[j - gap] > array[j]; j -= gap)
				swap_bubble(array + j, array + (j - gap));
		}
		print_array(array, size);
	}
}
