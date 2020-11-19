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
 * execute - function that execute the arguments received
 * @args: arguments
 */

void execute(char **args, char *c, char *b)
{
	int status, i = 0;
	pid_t childn;
	char *path;

	childn = fork();
	if (childn == -1)
	{
		perror("Error");
		while (args[i])
			free(args[i++]);
		free(args);
		exit(EXIT_FAILURE);
	}
	if (childn == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			path = find_path(args[0]);
			if (path)
			{
				args[0] = _strdup(path);
				execve(args[0], args, NULL);
				exit(EXIT_SUCCESS);
			}
			else
			{
				while (args[0][i])
					i++;
				write(STDOUT_FILENO, args[0], i);
				write(STDOUT_FILENO, ": ", 3);
				write(STDOUT_FILENO, "Invalid command\n", 17);
				i = 0;
				while (args[i])
					free(args[i++]);
				free(args);
				free(c);
				free(b);
				exit(EXIT_FAILURE);
			}
		}
	}
	else
		wait(&status);
}

/**
 * find_path - function that find the route of the identifier.
 * @exname: name of executable.
 * Return: pointer to the route.
 */

char *find_path(char *exname)
{
	char *name = "PATH", *route;
	char *getenvp, **directory;
	int i = 0;
	struct stat dir_stat;

	getenvp = _getenv(name);
	directory = call_strtok(getenvp, ":");
	for (i = 0; directory[i]; i++)
	{
		route = str_concat(directory[i], exname);
		if (stat(route, &dir_stat) == 0)
			return (route);
		free(route);
	}
	i = 0;
	while (directory[i])
		free(directory[i++]);
	free(directory);
	free(getenvp);
	return (NULL);
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
	con = malloc(sizeof(char) * (i + j + 2));
	if (con == 0)
		return (0);
	for (k = 0; k < i; k++)
		con[k] = s1[k];
	con[k++] = '/';
	for (l = 0; l < j; l++)
		con[k++] = s2[l];
	con[k] = '\0';
	return (con);
}
