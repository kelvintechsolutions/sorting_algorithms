#include "sort.h"

/**
 * swap_bubble -this functio sorts with swap method.
 *@a:it is the element to be swapped.
 *@b:it is the element to be swapped.
 * Return:it returns nothing.
 */

void swap_bubble(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort -it sorts an array using bubble sort algorithm.
 *@array: array to be sorted.
 *@size:it is the size to be sorted.
 * Return:it is  void.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, sz = size;
	bool booln = false;

	if (array == NULL || size < 2)
		return;

	while (booln == false)
	{
		booln = true;
		for (i = 0; i < sz - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_bubble(array + i, array + i + 1);
				print_array(array, size);
				booln = false;
			}
		}
		sz--;
	}
}
