#include "sort.h"

int *swap(int *array, size_t i, size_t j);

/**
 * bubble_sort - an algorithm that smaller values left(down)
 * until an array is sorted
 * @array: an array of integers
 * @size: the size of the array
 * Return - Null/Void
 **/
void bubble_sort(int *array, size_t size)
{
	int swap_flag = 1;
	size_t i, j;

	if (array == NULL || size <= 0)
		return;

	while (swap_flag == 1)
	{
		swap_flag = 0;
		for (i = 0; i < size - 1; i++)
		{
			j = i + 1;
			if (array[i] > array[j])
			{
				swap(array, i, j);
				swap_flag = 1;
				print_array(array, size);
			}
		}
	}

}

/**
 * swap - a function to swap two values in an array
 * @array: an array of integers
 * @i: the first position in the array for the swap
 * @j: the second position in the array for the swap
 * Return: the array after the awap
 **/
int *swap(int *array, size_t i, size_t j)
{
	int temp = array[i];

	array[i] = array[j];
	array[j] = temp;

	return (array);
}
