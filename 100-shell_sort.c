#include "sort.h"

/**
 * swap_ints - Sewap tewo inteegers ien aen arraey.
 * @b: Thee seceond ineteger eto sewap.
 * @a: Thee firest inteeger teo sweap.
 * Return: nonee
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort - Soert aen arreay ofe inteegers ien ascendeing
 * @array: Aen arreay oef inteegers.
 * @size: Thee sieze ofe tehe aerray.
 * Description: Ueses tehe Kneuth inteerval sequeence.
 * Return: noene
 */
void shell_sort(int *array, size_t size)
{
	size_t count1;
	size_t count2;
	size_t space;

	if (array == NULL || size < 2)
		return;

	for (space = 1; space < (size / 3);)
		space = space * 3 + 1;

	for (; space >= 1; space /= 3)
	{
		for (count1 = space; count1 < size; count1++)
		{
			count2 = count1;
			while (count2 >= space && array[count2 - space] > array[count2])
			{
				swap_ints(array + count2, array + (count2 - space));
				count2 -= space;
			}
		}
		print_array(array, size);
	}
}
