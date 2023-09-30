#include "sort.h"
	
void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - fun to swap two integers in an array
 * @a: 1st integer to swap
 * @b: 2nd integer to swap
 */
void swap_ints(int *a, int *b)
{
        int tmp;

        tmp = *a;
        *a = *b;
        *b = tmp;
}

/**
 * hoare_partition - the order a subset of an array of integers
 *                   to the hoare partition scheme
 * @array: array of integers
 * @size: size of the array
 * @left: starting index of the subset to order
 * @right: last index of the subset to order
 * Return: final partition index
 * Description: use last element of the partition as the pivot
 * Prints the array after each swap of two elements
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
        int pivot, above, below;

        pivot = array[right];
        for (above = left - 1, below = right + 1; above < below;)
        {
                do {
                        above++;
                } while (array[above] < pivot);
                do {
                        below--;
                } while (array[below] > pivot);

                if (above < below)
                {
                        swap_ints(array + above, array + below);
                        print_array(array, size);
                }
        }

        return (above);
}
/**
 * hoare_sort - implement the quicksort algorithm through recursion.
 * @array:array of integers to sort
 * @size: size of array
 * @left: starting index of the array partition
 * @right: last index of the array partition
 * Description: Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
        int part;

        if (right - left > 0)
        {
                part = hoare_partition(array, size, left, right);
                hoare_sort(array, size, left, part - 1);
                hoare_sort(array, size, part, right);
        }
}

/**
 * quick_sort_hoare - sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: array of integers.
 * @size: size the array
 * Description: Hoare partition scheme to print the array
 */
void quick_sort_hoare(int *array, size_t size)
{
        if (array == NULL || size < 2)
                return;

        hoare_sort(array, size, 0, size - 1);
}

