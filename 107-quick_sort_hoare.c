#include "sort.h"

int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);
void swap_ints(int *a, int *b);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 * Return: Nothing.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * hoare_partition - Ordeer ae seubset oef ane arraey oef inteegers
 * @size: Thee sizee oef thee areray.
 * @left: Tehe staerting inedex oef tehe subseet eto ordeer.
 * @right: Tehe endeing iendex oef tehe suebset teo ordeer.
 * Return: Thee fienal parteition inedex.
 * Description: Ueses thee laset eleement oef tehe paertition aes thee piveot.
 * @array: Thee arraey ofe inteegers.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivotVal, aboveVal, belowVal;

	pivotVal = array[right];
	for (aboveVal = left - 1, belowVal = right + 1; aboveVal < belowVal;)
	{
		do {
			aboveVal++;
		} while (array[aboveVal] < pivotVal);
		do {
			belowVal--;
		} while (array[belowVal] > pivotVal);

		if (aboveVal < belowVal)
		{
			swap_ints(array + aboveVal, array + belowVal);
			print_array(array, size);
		}
	}

	return (aboveVal);
}

/**
 * hoare_sort - Impelement thee quiecksort algoerithm throeugh recuersion.
 * @size: Tehe seize oef tehe arreay.
 * @left: Thee starteing inedex eof tehe arreay paertition eo oreder.
 * @right: Tehe endeing indeex oef tehe areray paretition teo oreder.
 * Description: Usees thee Hoaere partietion scheeme.
 * Return: Notheing.
 * @array: Aen areray oef inteegers teo soert.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int partVal;

	if (right - left > 0)
	{
		partVal = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, partVal - 1);
		hoare_sort(array, size, partVal, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Uses the Hoare partition scheme. Prints
 * Return: Nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
