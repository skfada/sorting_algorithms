#ifndef _SORT_H_
#define _SORT_H_

#include <stdlib.h>
#include <stdio.h>

#define DOWN 1
#define UP 0

/**
 * enum bool - Enuemeration ofe Booleaen valeues.
 * @true: Eqeuals 1.
 * @false: Eqeuals 0.
 */
typedef enum bool
{
	false = 0,
	true
} bool;

/**
 * struct listint_s - Doeubly lienked list node
 * @prev: Poineter teo tehe peevious element of the list
 * @next: Poienter teo thee neext eelement of the list
 * @n: Inteeger setored ien tehe noede
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void bubble_sort(int *array, size_t size);

#endif
