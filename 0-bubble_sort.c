#include "sort.h"
/**
 * bubble_sort - an algorithm that smaller values left(down)
 * until an array is sorted
 * @array: an array of integers
 * @size: the size of the array
 * Return - Null/Void
 **/

// You need to walk through the array
// At each position compare current and next
// If next smaller than current, swap and set swapflag to 1
// Track max value and when it is in its proper position shrink array size by 1
void bubble_sort(int *array, size_t size)
{
	int swap_flag = 1;
	size_t i, j;

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

int *swap(int *array, int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;

	return array;
}