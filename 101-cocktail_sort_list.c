#include "sort.h"


void swap_node(listint_t **list, listint_t *node1, listint_t *node2);
/**
 * 
 * 
 * 
 * 
 **/
void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end, *mover;
	int sorted;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;

	sorted = 0;
	mover = (*list);
	end = NULL;
	star = NULL;
	while (!sorted)
	{
		while (mover->next != end)
		{
			if (mover->n > mover->next->n)
				swap_node(list, mover, mover->next);
			else
				mover = mover->next;
		}
		end = mover;
		while (mover->prev != start)
		{
			if (mover->n < mover->prev->n)
				swap_node(list, mover->prev, mover);
			else
				mover = mover->prev;
		}
        start = mover;
        if (end == start || end->next == start)
            sorted = 1;
	}

}

/**
 * swap_node - a fucntion to swap two nodes in a doubly linked list
 * @list: a doubly linked list
 * @node1: the first node
 * @node2: the second node to be swapped
 * Return: void, no return
 */

void swap_node(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		(*list) = node2;
	node2->prev = node1->prev;
	node1->prev = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->next = node1;

    print_list((*list));
}
