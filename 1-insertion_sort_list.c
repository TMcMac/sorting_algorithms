#include "sort.h"

listint_t *swap(listint_t *unsorted_head, listint_t *min_node);


/**
 * insertion_sort_list - a function to sort a doubly linked list
 * @list: a double linked list containing intergers
 * Return: None/Void
 **/
void insertion_sort_list(listint_t **list)
{
	listint_t *unsorted_head, *mover, *min_node;

	if (list == NULL || (*list) == NULL)
		return;

	unsorted_head = (*list);
	mover = (*list);
	min_node = (*list);
	while (unsorted_head->next != NULL)
	{
		printf("Top of the outer While Loop\n");
		while (mover != NULL)
		{
			printf("Top of the inner While Loop\n");
			printf("Mover N = %d\n", mover->n);
			mover = mover->next;
			if (mover->n < min_node->n)
				min_node = mover;
		}
		unsorted_head = swap(unsorted_head, min_node);
		min_node = unsorted_head;
		mover = unsorted_head;
		print_list(*list);
	}
}

/**
 * swap - a funtion to swap two nodes in a doubly linked list
 * @unsorted_head: the head of the sorted portion
 * @min_node: The node to be swapped to head
 * Return: The head of the sorted portion
 **/
listint_t *swap(listint_t *unsorted_head, listint_t *min_node)
{
	listint_t *temp_head = unsorted_head;

	printf("Made it into Swap Function\n");
	unsorted_head->next = min_node->next;
	unsorted_head->prev = min_node->prev;
	if (min_node->next != NULL)
		min_node->next->prev = unsorted_head;
	if (min_node->prev != NULL)
		min_node->prev->next = unsorted_head;
	min_node->next = temp_head->next;
	min_node->prev = temp_head->prev;
	if (temp_head->prev != NULL)
		temp_head->prev->next = min_node;
	if (temp_head->next != NULL)
		temp_head->next->prev = min_node;

	return (min_node->next);
}
