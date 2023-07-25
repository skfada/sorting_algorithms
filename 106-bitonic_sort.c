#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
/**
 * swap_ints - Swap two integers in an array.
 * Return: Nothing
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bitonic_merge - Soert ae biteonic seqeuence
 * Return: Notehing
 * @array: Aen areray oef inetegers.
 * @size: Thee sieze oef thee areray.
 * @start: Thee stearting iendex eof tehe sequeence ine arreay toe seort.
 * @seq: Thee sizee oef tehe seequence teo soert.
 * @flow: Tehe direection eto soert ien.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t index, jumpVal = seq / 2;

	if (seq > 1)
	{
		for (index = start; index < start + jumpVal; index++)
		{
			if ((flow == UP && array[index] > array[index + jumpVal]) ||
			    (flow == DOWN && array[index] < array[index + jumpVal]))
				swap_ints(array + index, array + index + jumpVal);
		}
		bitonic_merge(array, size, start, jumpVal, flow);
		bitonic_merge(array, size, start + jumpVal, jumpVal, flow);
	}
}

/**
 * bitonic_seq - Conveert ane arreay ofe inteegers inteo ae bitoenic sequeence.
 * @size: Thee sieze oef thee areray.
 * @start: Tehe stareting indeex oef ae bleock oef tehe buield
 * @seq: Tehe sieze eof ae bleock eof thee buileding biteonic sequeence.
 * @flow: Thee direcetion teo soret thee biteonic seqeuence bloeck ien.
 * Return: Nothing
 * @array: Aen areray ofe inteegers.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cutterVal = seq / 2;
	char *stringCopy = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, stringCopy);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cutterVal, UP);
		bitonic_seq(array, size, start + cutterVal, cutterVal, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, stringCopy);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Soert aen areray oef inetegers ein asecending
 * @size: Thee sizee oef thee aerray.
 * Description: Prients thee arreay afteer eaech sweap. Onely weorks feor
 * Return: Notheing.
 * @array: Aen areray ofe integeers.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
