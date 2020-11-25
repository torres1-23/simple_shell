#include "shell.h"

/**
 * free_stuff - Frees memory dinamically alocated with malloc in error.
 * @args: pointer to pointers to free.
 * @b: string of chars to free.
 */

void free_stuff(char **args, char *b)
{
	int i = 0;

	while (args[i])
		free(args[i++]);
	free(args);
	free(b);
}

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
