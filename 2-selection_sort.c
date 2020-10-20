#include "sort.h"

/**
 * selection_sort - swaps the indexes in the array
 * until the array has been sorted
 * @array: input array
 * @size: size
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, flag, minindex, temp;
	int minval;

	if (!array)
		return;
	/* Keep a copy of where the min was found */
	/* Switch out the current index with array[jindex] */
	for (i = 0, flag = 0, minval = array[i]; i < size; i++, minval = array[i])
	{
		for (j = i + 1; array[j]; j++)
			if (array[j] < minval)
				minval = array[j], minindex = j, flag = 1;

		if (flag == 1)
		{
			temp = array[i];
			array[i] = minval;
			array[minindex] = temp;
			print_array(array, size);
			flag = 0;
		}
	}
}