#include "sort.h"

void swap(listint_t **list, listint_t *mover);


/**
 * insertion_sort_list - a function to sort a doubly linked list
 * @list: a double linked list containing intergers
 * Return: None/Void
 **/
void insertion_sort_list(listint_t **list)
{
	listint_t *mover, *trailer;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;

	mover = (*list);
	while (mover->next != NULL)
	{
		mover = mover->next;
		trailer = mover->prev;
		if (trailer->n > mover->n)
		{
			swap(list, mover);
			mover = trailer;
		}
	}
}

/**
 * swap - a funtion to swap two nodes in a doubly linked list
 * @list: the head of the sorted portion
 * @unsorted_node: The node to be swapped into propper position
 * Return: The head of the sorted portion
 **/
void swap(listint_t **list, listint_t *unsorted_node)
{
	listint_t *check = unsorted_node->prev;

	while (unsorted_node->n < check->n)
	{
		check = unsorted_node->prev;

		if (check->prev)
			check->prev->next = unsorted_node;
		if (unsorted_node->next)
			unsorted_node->next->prev = check;
		unsorted_node->prev = check->prev;
		check->next = unsorted_node->next;
		check->prev = unsorted_node;
		unsorted_node->next = check;
		if ((*list)->prev)
		{
			(*list) = unsorted_node;
			print_list((*list));
			return;
		}
	   	print_list((*list));
	}
}
