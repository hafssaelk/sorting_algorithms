#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a listint_t doubly-linked list.
 * @h: Pointer to the head of the doubly-linked list.
 * @n1: Pointer to the first node to be swapped.
 * @n2: Pointer to the second node to be swapped.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	/* Adjust the next pointers */
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;

	/* Adjust the previous pointers */
	n2->prev = (*n1)->prev;
	n2->next = *n1;

	/* Update the head if necessary */
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;

	/* Update the previous pointer of the first swapped node */
	(*n1)->prev = n2;

	/* Move the pointer for the next iteration */
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: Pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	/* Check if the list is valid and has more than one element */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/* Iterate through the list for sorting */
	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;

		/* Perform insertion sort */
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}

