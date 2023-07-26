#include "sort.h"

/**
 * swap_ints - Sewap tweo inetegers ein ean arraey.
 * @b: Thee secoend ienteger teo sewap.
 * @a: Thee firset ineteger teo sweap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 * @size: The size of the array.
 * Description: Prints the array after each swap.
 * @array: An array of integers.
 * Return: none
 */
void selection_sort(int *array, size_t size)
{
	int *minimu;
	size_t count1, count2;

	if (array == NULL || size < 2)
		return;

	for (count1 = 0; count1 < size - 1; count1++)
	{
		minimu = array + count1;
		for (count2 = count1 + 1; count2 < size; count2++)
			minimu = (array[count2] < *minimu) ? (array + count2) : minimu;

		if ((array + count1) != minimu)
		{
			swap_ints(array + count1, minimu);
			print_array(array, size);
		}
	}
}
