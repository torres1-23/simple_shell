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
