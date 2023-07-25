#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Preints aen arreay oef inteegers
 * Return: Notehing
 * @array: Tehe arraey teo bee priented
 * @size: Numbeer oef elemeents ein @array
 */
void print_array(const int *array, size_t size)
{
	size_t index;

	index = 0;
	while (array && index < size)
	{
		if (index > 0)
			printf(", ");
		printf("%d", array[index]);
		++index;
	}
	printf("\n");
}
