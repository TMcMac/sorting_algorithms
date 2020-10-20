#include "sort.h"

void swap(listint_t *list, listint_t *mover);


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
			swap((*list), mover);
			mover = trailer;
		}
	}
}

/**
 * swap - a funtion to swap two nodes in a doubly linked list
 * @list: the head of the sorted portion
 * @unsorted_node: The node to be swapped into propper position
 * Return: The head of the sorted portion
 * */
void swap(listint_t *list, listint_t *unsorted_node)
{
	listint_t *check_prev = unsorted_node->prev;

	while (unsorted_node->n < check_prev->n)
	{
		if (check_prev->prev != NULL && unsorted_node->next != NULL)
		{
			check_prev->next = unsorted_node->next;
			unsorted_node->next->prev = check_prev;
			check_prev->prev->next = unsorted_node;
			unsorted_node->prev = check_prev->prev;
			check_prev->prev = unsorted_node;
			unsorted_node->next = check_prev;
			check_prev = unsorted_node->prev;
			print_list((*list));
		}
		else if (check_prev->prev != NULL)
		{
			check_prev->next = unsorted_node->next;
			unsorted_node->next->prev = check_prev;
			check_prev->prev = unsorted_node;
			unsorted_node->next = check_prev;
			unsorted_node->prev = NULL;
			(*list) = unsorted_node;
			print_list((*list));
			return;
		}
		else if (unsorted_node->next == NULL)
		{
			check_prev->prev->next = unsorted_node;
			unsorted_node->prev = check_prev->prev;
			unsorted_node->next = check_prev;
			check_prev->prev = unsorted_node;
			check_prev->next = NULL;
			print_list((*list));
		}
	}
	return;
}
