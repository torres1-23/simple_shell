#include "shell.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: string to duplicate.
 *
 * Return: a pointer to the duplicated string. It returns NULL if insufficient
 * memory was available.
 */

char *_strdup(char *str)
{
	char *copy;
	unsigned int i, l = 0;

	if (str == NULL)
		return (NULL);
	while (str[l])
		l++;
	copy = malloc((sizeof(char) * l) + 1);
	if (copy == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
		copy[i] = str[i];
	copy[i] = '\0';
	return (copy);
}

/**
 * call_strtok - function that breaks string into tokens
 * @str: string to break
 * @delimit: delimiter
 * Return: pointer to the first token found in the string
 */

char **call_strtok(char *str, char *delimit)
{
	char **arrword;
	char *word, *tmp;
	int con = 0, i = 0;

	tmp = _strdup(str);
	word = strtok(str, delimit);
	while (word)
	{
		con++;
		word = strtok(NULL, delimit);
	}
	arrword = malloc(sizeof(char *) * (con + 1));
	if (arrword == NULL)
		return (NULL);
	word = strtok(tmp, delimit);
	while (word)
	{
		arrword[i] = _strdup(word);
		word = strtok(NULL, delimit);
		i++;
	}
	arrword[i] = NULL;
	free(tmp);
	return (arrword);
}

/**
 * str_concat - function that concatenate two strings
 * @s1: first string
 * @s2: second string.
 * Return: pointer to the string concatenated.
 */

char *str_concat(char *s1, char *s2)
{
	int i = 0, j = 0, k, l;
	char *con;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	con = malloc(sizeof(char) * (i + j + 5));
	if (con == 0)
		return (NULL);
	for (k = 0; k < i; k++)
		con[k] = s1[k];
	con[k++] = '/';
	for (l = 0; l < j; l++)
		con[k++] = s2[l];
	con[k] = '\0';
	return (con);
}

/**
 * concat - function that concatenate two strings
 * @name: first string
 * @value: second string.
 * @index: index to start concatenating.
 * Return: pointer to the string concatenated.
 */

char *concat(char *name, char *value, int index)
{
	int len = 0, len1 = 0, i = 0, j = 0;

	while (name[len])
		len++;
	if (value)
	{
		while (value[len1])
			len1++;
	}
	else
		value = "";
	environ[index] = malloc(sizeof(char) * (len + len1 + 2));
	for (i = 0; i < len; i++)
		environ[index][i] =  name[i];
	environ[index][i++] = '=';
	for (j = 0; j < len1; j++)
		environ[index][i++] = value[j];
	environ[index][i] = '\0';
	return (environ[index]);
}

/**
 * delspace - Function that deletes space before find a character
 * @str: string to remove the space
 * @copy: string without spaces.
 * @index: index to star to remove
 * Return: return a pointer to the new string starting with a caracter o null
 */

char *delspace(char *str, char *copy, int index)
{
	char *space = " ";
	int i = index, j = 0;

	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] != space[0])
			break;
		i++;
	}
	for (j = 0; str[i]; j++)
		copy[j] = str[i++];
	copy[j] = '\0';
	return (copy);
}