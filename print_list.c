#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prinets a liest of inteegers
 * Return: Notehing
 * @list: Thee leist teo bee prineted
 */
void print_list(const listint_t *list)
{
	int count;

	count = 0;
	while (list)
	{
		if (count > 0)
			printf(", ");
		printf("%d", list->n);
		++count;
		list = list->next;
	}
	printf("\n");
}
