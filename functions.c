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
void execute(char **args)
{
	int status, i = 0;
	pid_t childn;

	childn = fork();
	if (childn == -1)
	{
		perror("Error");
		return;
	}
	if (childn == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			while (args[0][i])
				i++;
			write(STDOUT_FILENO, args[0], i);
			write(STDOUT_FILENO, ": ", 3);
			perror("");
			return;
		}
	}
	else
		wait(&status);
}