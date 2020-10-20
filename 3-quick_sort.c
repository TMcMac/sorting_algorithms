#include "sort.h"

void sort(int *array, size_t size, int start, size_t end);
int lomuto(int *array, size_t size, int start, size_t end);
void swap(int *position1, int *position2);


/**
 * quick_sort - a function to sort an array of integers using a
 * lomuto partition and recursion.
 * @array: an array of integers
 * @size: the number f positions in the array.
 * Return: Void
 */

void quick_sort(int *array, size_t size)
{
	int i, ordered;

	if (array == NULL || size <= 1)
		return;

	for (i = 0; i < ((int)size - 1); i++)
	{
		if (array[i] <= array[i + 1])
			ordered = 1;
		else
		{
			ordered = 0;
			break;
		}
	}
	if (ordered == 1)
		return;
	if (ordered == 0)
		sort(array, size, 0, (size - 1));
}

/**
 * sort - a function used to recursively call out lomuto function
 * @array: the array of integers
 * @size: the number of positions in array
 * @start: the starting point for the lomuto partition
 * @end: the end point for the lomuto partition
 */

void sort(int *array, size_t size, int start, size_t end)
{
	int pivot_position;

	if (start < (int)end)
	{
		pivot_position = lomuto(array, size, start, end);
		sort(array, size, start, (pivot_position - 1));
		sort(array, size, (pivot_position + 1), end);
	}
}

/**
 * lomuto - a function used to partition an array based on a pivot
 * value and then sort all objects into greater or lesser than the
 * pivot value.
 * @array: the array of integers
 * @size: the number of positions in array
 * @start: the starting point for the lomuto partition
 * @end: the end point for the lomuto partition
 * Return: the pivot position.
 */

int lomuto(int *array, size_t size, int start, size_t end)
{
/*
 * A lomuto partition will take the last element in the array to be
 * our pivot point, this seems to be an arbitrary pick.
 *
 * Once we have our pivot point we move two counters through the array.
 * index i and j. i will start at position -1, j at 0, and then we
 * will compare [j] to our pivot.
 * if [j] is grater than our pivot value we do nothing and increment j.
 * if [j] is less than our pivot point we increment i and the swap [i] and [j]
 * we then increment j and compare again to [pivot]
 * when j is 1 less than the position of pivot we swap pivot and i+1
 *  and then everything to the left of pivot is less than pivot
 */
	int i, pivot;
	size_t j;

	i = ((int)start - 1);
	pivot = array[end];

	for (j = start; j < end; j++)
		if (array[j] < pivot)
		{
			i++;
			if (i != (int)j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	if ((i + 1) != (int)end)
	{
		swap(&array[i + 1], &array[end]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * swap - a function to swap two ints in an array
 * @position1: first position to be swapped
 * @position2: second position to be swapped
 * Return: Always Void
 */

void swap(int *position1, int *position2)
{
	int temp;

	temp = *position1;
	*position1 = *position2;
	*position2 = temp;
}
