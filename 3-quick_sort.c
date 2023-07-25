#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - will swap two ints in an array
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
 * lomuto_partition - will order a subset of an array of ints according to
 *                    the lomuto partition scheme
 * @array: Array of ints
 * @size: Array size
 * @left: Starting index of the subset to order
 * @right: Ending index of subset to order
 *
 * Return: Final partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *driver, up, down;

	driver = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *driver)
		{
			if (up < down)
			{
				swap_ints(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *driver)
	{
		swap_ints(array + up, driver);
		print_array(array, size);
	}

	return (up);
}

/**
 * lomuto_sort - will implement the quicksort algorithm through recursion
 * @array: Array of ints to be sorted
 * @size: Size of array
 * @left: Starting index of array partition to order
 * @right: Ending index of array partition to order
 *
 * Description: Uses Lomuto partition scheme
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int belong;

	if (right - left > 0)
	{
		belong = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, belong - 1);
		lomuto_sort(array, size, belong + 1, right);
	}
}

/**
 * quick_sort -will  sort an array of ints in ascending
 *              order using the quicksort algorithm.
 * @array: Array of ints
 * @size: size of array
 *
 * Description: will use Lomuto partition scheme. Prints
 *              the array after each swap of two elements
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
