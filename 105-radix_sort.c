#include "sort.h"

<<<<<<< HEAD
=======
int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

>>>>>>> f3ad1316846d10ed495057bbd57e64db4f18eb3e
/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
<<<<<<< HEAD
 * radix_counting_sort - Perform counting sort on the significant digits of
 *                       an array of integers in ascending order.
=======
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
>>>>>>> f3ad1316846d10ed495057bbd57e64db4f18eb3e
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
<<<<<<< HEAD
	int count[10] = {0};
	size_t i;

	/* Count occurrences of each digit at the current significant place */
	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	/* Modify the count array to store the cumulative count */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array by placing elements in their correct positions */
=======
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

>>>>>>> f3ad1316846d10ed495057bbd57e64db4f18eb3e
	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

<<<<<<< HEAD
	/* Copy the sorted elements back to the original array */
=======
>>>>>>> f3ad1316846d10ed495057bbd57e64db4f18eb3e
	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
<<<<<<< HEAD
 * radix_sort - Sort an array of integers in ascending order using
 *              the LSD (Least Significant Digit) radix sort algorithm.
=======
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
>>>>>>> f3ad1316846d10ed495057bbd57e64db4f18eb3e
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
<<<<<<< HEAD
 * the array after each increase in significant digits.
=======
 * the array after each significant digit increase.
>>>>>>> f3ad1316846d10ed495057bbd57e64db4f18eb3e
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
<<<<<<< HEAD

	/* Perform LSD radix sort for each significant digit place */
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size); /* Print the array after each pass */
=======
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
>>>>>>> f3ad1316846d10ed495057bbd57e64db4f18eb3e
	}

	free(buff);
}
<<<<<<< HEAD

=======
>>>>>>> f3ad1316846d10ed495057bbd57e64db4f18eb3e
