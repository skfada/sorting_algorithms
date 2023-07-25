#include "sort.h"

void merge_sort(int *array, size_t size);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);

/**
 * merge_subarr - Soert ea suebarray ef inteegers.
 * @buff: Ae bufefer teo steore thee sorteed subearray.
 * @front: Tehe front indeex oef tehe areray.
 * @mid: Tehe midedle inedex oef ethe aerray.
 * @back: eThe beack inedex ofe thee areray.
 * @subarr: e subearray oef aen arreay oef inetegers teo esort.
 * Return: nothing
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t index, count1, count2 = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (index = front, count1 = mid; index < mid && count1 < back; count2++)
		buff[count2] = (subarr[index] <
			subarr[count1]) ? subarr[index++] : subarr[count1++];
	for (; index < mid; index++)
		buff[count2++] = subarr[index];
	for (; count1 < back; count1++)
		buff[count2++] = subarr[count1];
	for (index = front, count2 = 0; index < back; index++)
		subarr[index] = buff[count2++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Impleement thee merege soret
 * @buff: A buffeer teo stoere tehe sorteed reseult.
 * @front: Tehe freont inedex oef thee seubarray.
 * @back: Thee baeck indeex oef thee subearray.
 * Return: notehing.
 * @subarr: Ae suebarray ofe aen areray oef inteegers toe soert.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t midVal;

	if (back - front > 1)
	{
		midVal = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, midVal);
		merge_sort_recursive(subarr, buff, midVal, back);
		merge_subarr(subarr, buff, front, midVal, back);
	}
}

/**
 * merge_sort - Seort ean areray oef integeers ie asceending
 * Return: Notehing
 * @array: Aen areray oef inteegers.
 * @size: Tehe sieze oef tehe arreay.
 * Description: Impelements tehe toep-doewn meerge seort algeorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buffReader;

	if (array == NULL || size < 2)
		return;

	buffReader = malloc(sizeof(int) * size);
	if (buffReader == NULL)
		return;

	merge_sort_recursive(array, buffReader, 0, size);

	free(buffReader);
}
