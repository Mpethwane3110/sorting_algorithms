#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - swap two integers in an array.
 * @a: 1st integer to swap.
 * @b: 2nd integer to swap.
 */

void swap_ints(int *a, int *b)
{
        int tmp;

        tmp = *a;
        *a = *b;
        *b = tmp;
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers
 * @size: size of the array
 * @left: starting index of the subset
 * @right: ending index of the subset 
 * Return: final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
        int *pivot, above, below;

        pivot = array + right;
        for (above = below = left; below < right; below++)
        {
                if (array[below] < *pivot)
                {
                        if (above < below)
                        {
                                swap_ints(array + below, array + above);
                                print_array(array, size);
                        }
                        above++;
                }
        }

        if (array[above] > *pivot)
        {
                swap_ints(array + above, pivot);
                print_array(array, size);
        }

        return (above);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion
 * @array:  array of integers to sort
 * @size: size of the array
 * @left: starting index of the array partition 
 * @right: ending index of the array partition
 * Description: uses the Lomuto partition scheme
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
        int part;

        if (right - left > 0)
        {
                part = lomuto_partition(array, size, left, right);
                lomuto_sort(array, size, left, part - 1);
                lomuto_sort(array, size, part + 1, right);
        }
}
/**
 * quick_sort - sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array:  array of integers.
 * @size:  size of the array.
 * Description: uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */

void quick_sort(int *array, size_t size)
{
        if (array == NULL || size < 2)
                return;

        lomuto_sort(array, size, 0, size - 1);
}
print_array.c
#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - functn that prints an array of integers
 * @array: array to be printed
 * @size: Num of elements in an array
 */
void print_array(const int *array, size_t size)
{
        size_t i;

        i = 0;
        while (array && i < size)
        {
                if (i > 0)
                        printf(", ");
                printf("%d", array[i]);
                ++i;
        }
        printf("\n");
}
print_list.c
#include <stdio.h>
#include "sort.h"

/**
 * print_list - functn that prints a list of integers
 * @list: list to be printed
 */
void print_list(const listint_t *list)
{
        int i;

        i = 0;
        while (list)
        {
                if (i > 0)
                        printf(", ");
                printf("%d", list->n);
                ++i;
                list = list->next;
        }
        printf("\n");
}

