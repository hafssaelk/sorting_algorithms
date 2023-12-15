#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence for gap calculation.
 *              Prints the array after each gap iteration.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	/* Calculate the initial gap using the Knuth interval sequence */
	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	/* Perform shell sort with decreasing gap sizes */
	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;

			/* Insertion sort within the current gap */
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_ints(array + j, array + (j - gap));
				j -= gap;
			}
		}

		/* Print the array after each gap iteration */
		print_array(array, size);
	}
}
