#include "sort.h"

/**
 * swap_ints - will swap two int's in an array
 * @a: 1st integer to be swapped
 * @b: 2nd integer to be swapped
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - will sort an array of int's in ascending order
 * @array: array of int's to be sorted
 * @size: size of array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t ui, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (ui = 0; ui < len - 1; ui++)
		{
			if (array[ui] > array[ui + 1])
			{
				swap_ints(array + ui, array + ui + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
