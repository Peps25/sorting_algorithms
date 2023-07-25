#include "sort.h"

/**
 * swap_ints - will swap two int's in an array
 * @a: 1st int to be swapped
 * @b: 2nd int to be swapped
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - will sort an array of int's in ascending order
 *                  using the selection sort algorithm.
 * @array: Array of int's
 * @size: Size of array
 *
 * Description: will print the array after each swap
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t j, k;

	if (array == NULL || size < 2)
		return;

	for (j = 0; j < size - 1; j++)
	{
		min = array + j;
		for (k = j + 1; k < size; k++)
			min = (array[k] < *min) ? (array + k) : min;

		if ((array + j) != min)
		{
			swap_ints(array + j, min);
			print_array(array, size);
		}
	}
}
