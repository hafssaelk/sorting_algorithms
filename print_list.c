#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a doubly linked list of integers.
 *
 * @list: Pointer to the head of the list to be printed.
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

