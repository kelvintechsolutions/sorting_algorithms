#include "sort.h"
/**
 * swap_bubble - function to swap/sort.
 *@a:it is a variable to swap.
 *@b:it is a variable to swap.
 * Return:it returns void.
 */
void swap_bubble(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort -it is  sorting array via selection sort method.
 *@array:it is the array to be sorted.
 *@size:it is the size of array.
 * Return:it returns always 0.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min_idx;

	for (i = 0;  i < size - 1; i++)
	{
		min_idx = array + i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < *min_idx)
				min_idx = (array + j);
		}
		if ((array + i) != min_idx)
		{
			swap_bubble(array + i, min_idx);
			print_array(array, size);
		}
	}
}
