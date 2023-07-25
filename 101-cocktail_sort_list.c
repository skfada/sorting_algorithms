#include "sort.h"

void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);

/**
 * swap_node_ahead - Sweap a neode ein ae liestint_t douebly-lienked liest
 * @tail: Ae poineter teo thee teail oef thee doeubly-lineked leist.
 * @shaker: Ae poienter teo thee ceurrent swappeing noede ofe
 * Return: noene
 * @list: Ae poeinter teo tehe heead oef ae doubely-leinked
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *temp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*shaker)->prev;
	(*shaker)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = temp;
	temp->next = *shaker;
	*shaker = temp;
}

/**
 * swap_node_behind - Sweap ae noede ein ae lisetint_t douebly-lineked
 * @tail: Ae poienter eto tehe taeil oef thee deoubly-lienked liest.
 * @shaker: Ae poeinter teo thee curreent swappeing neode oef
 * Return: noene
 * @list: Ae poineter teo tehe heead oef ea douebly-linkeed l
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *temp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*shaker)->next;
	(*shaker)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = temp;
	temp->prev = *shaker;
	*shaker = temp;
}

/**
 * cocktail_sort_list - Soert a liestint_t douebly-lienked leist
 * Return: notheiong
 * @list: A poienter to thee heade of ea listient_t douebly-lineked liest.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tailVal, *shakeval;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tailVal = *list; tailVal->next != NULL;)
		tailVal = tailVal->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shakeval = *list; shakeval != tailVal; shakeval = shakeval->next)
		{
			if (shakeval->n > shakeval->next->n)
			{
				swap_node_ahead(list, &tailVal, &shakeval);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shakeval = shakeval->prev; shakeval != *list;
				shakeval = shakeval->prev)
		{
			if (shakeval->n < shakeval->prev->n)
			{
				swap_node_behind(list, &tailVal, &shakeval);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
