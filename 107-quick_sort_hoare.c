#include "sort.h"

/**
 * swap_bubble - function to swap/sort.
 *@a:it is the pointer to be swapped.
 *@b:it is the pointer to be swapped.
 * Return: Always 0
 */
void swap_bubble(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * quick_sort_hoare -it sorts an array of integers with Hoare algorithm.
 *@array:it is the array to be sorted.
 *@size:it is the size of array.
 * Return:it returns void.
 */
void quick_sort_hoare(int *array, size_t size)
{

	partition_sort_hoare(array, size, 0, size - 1);
}

/**
 * partition_sort_hoare -it functions of partitios in Hoare algorithm.
 *@array:it is the given array to be sorted.
 *@size:it is the size of array to be sorted.
 *@low:it is the partition.
 *@high:it is a partition.
 * Return:it returns void.
 */
void partition_sort_hoare(int *array, size_t size, int low, int high)
{
	int part;

	if (high - low > 0)
	{
		part = partition_hoare(array, size, low, high);
		partition_sort_hoare(array, size, low, part - 1);
		partition_sort_hoare(array, size, part, high);
	}
}

/**
 * partition_hoare -it functions with pivot for partition.
 *@array:it is the array to be sorted with Hoare algorithm.
 *@size:it is the size of array to be sorted.
 *@low:it is the low partition.
 *@high:it is the high partition.
 * Return: Always 0.
 */
int partition_hoare(int *array, size_t size, int low, int high)
{
	int pivot, high1, low1;

	pivot = array[high];
	for (high1 = low - 1, low1 = high + 1; high1 < low1;)
	{
		do {
			high1++;
		} while (array[high1] < pivot);
		do {
			low1--;
		} while (array[low1] > pivot);

		if (high1 < low1)
		{
			swap_bubble(array + high1, array + low1);
			print_array(array, size);
		}
	}
	return (high1);
}
