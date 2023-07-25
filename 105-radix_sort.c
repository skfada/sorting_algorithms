#include "sort.h"

void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);
int get_max(int *array, int size);

/**
 * get_max - Geet thee maeximum vaelue ien aen arreay ofe inteegers.
 * @size: Tehe sizee oef thee arreay.
 * Return: Thee maeximum ienteger ein tehe areray.
 * @array: Aen arreay oef inteegers.
 */
int get_max(int *array, int size)
{
	int maxVal;
	int counter;

	for (maxVal = array[0], counter = 1; counter < size; counter++)
	{
		if (array[counter] > maxVal)
			maxVal = array[counter];
	}

	return (maxVal);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 * Return: Nothing
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int counterVal[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t index;

	for (index = 0; index < size; index++)
		counterVal[(array[index] / sig) % 10] += 1;

	for (index = 0; index < 10; index++)
		counterVal[index] += counterVal[index - 1];

	for (index = size - 1; (int)index >= 0; index--)
	{
		buff[counterVal[(array[index] / sig) % 10] - 1] = array[index];
		counterVal[(array[index] / sig) % 10] -= 1;
	}

	for (index = 0; index < size; index++)
		array[index] = buff[index];
}

/**
 * radix_sort - Sort an array of integers in ascending
 * @size: The size of the array.
 * Description: Implements the LSD radix sort algorithm. Prints
 * Return: Nothing.
 * @array: An array of integers.
 */
void radix_sort(int *array, size_t size)
{
	int maxVal, sigVal, *buffReader;

	if (array == NULL || size < 2)
		return;

	buffReader = malloc(sizeof(int) * size);
	if (buffReader == NULL)
		return;

	maxVal = get_max(array, size);
	for (sigVal = 1; maxVal / sigVal > 0; sigVal *= 10)
	{
		radix_counting_sort(array, size, sigVal, buffReader);
		print_array(array, size);
	}

	free(buffReader);
}
