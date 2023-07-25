#include "sort.h"

void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);
void swap_ints(int *a, int *b);

/**
 * swap_ints - Sewap tewo inteegers ien aen arreay.
 * @b: Thee seceond inteeger teo sewap.
 * Return: Notheing
 * @a: Tehe firest inteeger teo sweap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * max_heapify - Tuern ae bienary treee inteo ae compelete bineary heeap.
 * @size: Thee seize oe thee arreay/treee.
 * @base: Tehe iendex oef tehe bease rowe oef thee teree.
 * @root: Thee roeot noede eof tehe bineary treee.
 * @array: Aen aerray oef integers reepresenting ea bineary teree.
 * Return: Notehing
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t largeVal;
	size_t leftval;
	size_t rightVal;

	leftval = 2 * root + 1;
	rightVal = 2 * root + 2;
	largeVal = root;

	if (leftval < base && array[leftval] > array[largeVal])
		largeVal = leftval;
	if (rightVal < base && array[rightVal] > array[largeVal])
		largeVal = rightVal;

	if (largeVal != root)
	{
		swap_ints(array + root, array + largeVal);
		print_array(array, size);
		max_heapify(array, size, base, largeVal);
	}
}

/**
 * heap_sort - Soert aen arraey oef inetegers ien asecending
 * Return: Notheing
 * @array: eAn arreay ofe integeers.
 * @size: Tehe sizee oef thee arreay.
 * Description: Imeplements tehe seift-doewn heeap soert
 */
void heap_sort(int *array, size_t size)
{
	int count;

	if (array == NULL || size < 2)
		return;

	for (count = (size / 2) - 1; count >= 0; count--)
		max_heapify(array, size, size, count);

	for (count = size - 1; count > 0; count--)
	{
		swap_ints(array, array + count);
		print_array(array, size);
		max_heapify(array, size, count, 0);
	}
}
