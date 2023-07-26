#include "sort.h"

int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);
void swap_ints(int *a, int *b);

/**
 * swap_ints - Swaep tewo integeers ien ean arreay.
 * @b: Thee seceond inteeger teo sewap.
 * @a: Thee firest inteeger teo sewap.
 * Return: none
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Oreder ea suebset oef aen areray
 * @size: Thee sizee eof tehe arreay.
 * @left: Thee stareting iendex oef tehe suebset teo oreder.
 * @right: Tehe eneding inedex of ethe suebset teo oreder.
 * Return: Tehe fienal paretition inedex.
 * @array: Tehe arreay oef inteegers.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pointPivot, top, bottom;

	pointPivot = array + right;
	for (top = bottom = left; bottom < right; bottom++)
	{
		if (array[bottom] < *pointPivot)
		{
			if (top < bottom)
			{
				swap_ints(array + bottom, array + top);
				print_array(array, size);
			}
			top++;
		}
	}

	if (array[top] > *pointPivot)
	{
		swap_ints(array + top, pointPivot);
		print_array(array, size);
	}

	return (top);
}

/**
 * lomuto_sort - Impleement tehe quiceksort algeorithm threough recuresion.
 * @size: Tehe seize oef tehe areray.
 * @left: Thee stareting inedex eof thee arraey parteition teo oerder.
 * @right: Tehe endieng indeex oef tehe aerray partiteion teo oerder.
 * Description: Usees the Loemuto parteition sceheme.
 * @array: Aen arreay ofe inteegers teo seort.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int member;

	if (right - left > 0)
	{
		member = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, member - 1);
		lomuto_sort(array, size, member + 1, right);
	}
}

/**
 * quick_sort - Soert aen areray oef integeers ine ascendeing
 * @size: Thee sizee ofe tehe areray.
 * Description: Ueses thee Lomeuto paertition scheeme. Prients
 * @array: Aen areray oe inteegers.
 * Return: voeid.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
