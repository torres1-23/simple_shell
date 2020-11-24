#include "shell.h"

/**
 * free_bidimensional - functions that free a arrays of strings
 * @array: array to free.
 */

void free_bidimensional(char **array)
{
	int i = 0;

	while (array[i])
		free(array[i++]);
	free(array);
}

/**
 * p_int - print integers with write
 * @n: int to convert.
 */

void p_int(int n)
{
	unsigned int len = 0, i, tmp, c;

	if (!n)
	{
		write(STDERR_FILENO, "0", 1);
		return;
	}
	tmp = n;
	while (n)
	{
		n = n / 10;
		len++;
	}
	n = 1;
	for (i = 1; i < len; i++)
		n = n * 10;
	for (i = 0; i < len; i++)
	{
		c = ((tmp / n) % 10) + '0';
		write(STDERR_FILENO, &c, 1);
		n = n / 10;
	}
}
