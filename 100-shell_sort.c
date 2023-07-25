#include "sort.h"


/**
 * swap_ints - will swap two ints in an array.
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
 * shell_sort - will sort array of ints in ascending
 *              order using shell sort algorithm
 * @array: Array of ints
 * @size: Size of array
 *
 * Description: Usage of the Knuth interval sequence
 */
void shell_sort(int *array, size_t size)
{
    size_t gap, ui, j;


    if (array == NULL || size < 2)
        return;


    for (gap = 1; gap < (size / 3);)
        gap = gap * 3 + 1;


    for (; gap >= 1; gap /= 3)
    {
        for (ui = gap; ui < size; ui++)
        {
            j = ui;
            while (j >= gap && array[j - gap] > array[j])
            {
                swap_ints(array + j, array + (j - gap));
                j -= gap;
            }
        }
        print_array(array, size);
    }
}
