#include "header.h"
/**
 * str_concat - concatenate two strings
 * @s1: string 1
 * @s2: string 2
 * Return: NULL if string is null, returns pointer to duplicated string
 */
char *str_concat(char *s1, char *s2)
{
	int i = 0, j = 0, k, l;
	char *con;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}

	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	con = malloc((i * sizeof(*s1)) + (j * sizeof(*s2)) + 1);
	if (con == 0)
		return (0);
	for (k = 0, l = 0; k < (i + j + 1); k++)
	{
		if (k < i)
			con[k] = s1[k];
		else
			con[k] = s2[l++];
	}
	con[k] = '\0';
	return (con);
}
