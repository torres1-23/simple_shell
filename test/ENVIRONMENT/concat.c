#include "header.h"

char *concat (const char *name, const char *value, int index)
{
	int len = 0, len1 = 0, i = 0, j = 0;

	while (name[len])
		len++;
	while (value[len1])
		len1++;

	environ[index] = malloc(sizeof(char) * (len + len1 + 2));
	for (i = 0; i < len; i++)
		environ[index][i] =  name[i];
	environ[index][i++] = '=';
	for (j = 0; j < len1; j++)
		environ[index][i++] = value[j];
	environ[index][i] = '\0';

	return(environ[index]);
}
