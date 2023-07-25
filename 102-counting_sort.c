#include "sort.h"


/**
 * get_max - will get maximum value in an array of ints
 * @array: Array of ints
 * @size: Array size
 *
 * Return: Maximum int in the array
 */
int get_max(int *array, int size)
{
    int max, ui;


    for (max = array[0], ui = 1; ui < size; ui++)
    {
        if (array[ui] > max)
            max = array[ui];
    }


    return (max);
}


/**
 * counting_sort - will sort an array of ints in ascending order
 *                 using the counting sort algorithm
 * @array: Array of ints
 * @size: Array size
 *
 * Description: prints counting array after setting it up
 */
void counting_sort(int *array, size_t size)
{
    int *count, *sorted, max, ui;


    if (array == NULL || size < 2)
        return;


    sorted = malloc(sizeof(int) * size);
    if (sorted == NULL)
        return;
    max = get_max(array, size);
    count = malloc(sizeof(int) * (max + 1));
    if (count == NULL)
    {
        free(sorted);
        return;
    }


    for (ui = 0; ui < (max + 1); ui++)
        count[ui] = 0;
    for (ui = 0; ui < (int)size; ui++)
        count[array[ui]] += 1;
    for (ui = 0; ui < (max + 1); ui++)
        count[ui] += count[ui - 1];
    print_array(count, max + 1);


    for (i = 0; ui < (int)size; ui++)
    {
        sorted[count[array[ui]] - 1] = array[ui];
        count[array[ui]] -= 1;
    }


    for (ui = 0; ui < (int)size; ui++)
        array[ui] = sorted[ui];


    free(sorted);
    free(count);
}
