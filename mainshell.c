#include "shell.h"
/**
 * main - Entry point
 * Simple shell written by Alejandro and Alejandra
 * Return: 0 in success.
 */
int main(void)
{
	char *buffer = NULL, **arr = NULL, *comand = NULL, *space = " ";
	size_t buffersize = 0;
	ssize_t numc = 0;
	int i = 0, j = 0;

	write(STDOUT_FILENO, "Alej@ Super Shell$ ", 20);
	while ((numc = getline(&buffer, &buffersize, stdin)) != -1)
	{
		i = 0;
		j = 0;
		comand = malloc(sizeof(char) * numc);
		buffer[numc - 1] = '\0';
		while (buffer[i])
		{
			if (buffer[i] != space[0])
				break;
			i++;
		}
		for (j = 0; j < numc; j++)
			comand[j] = buffer[i++];
		if (numc != 1 && comand[0])
		{
			arr = call_strtok(comand, " ");
			execute(arr);
			i = 0;
			while (arr[i])
			{
				free(arr[i]);
				i++;
			}
			free(arr);
		}
		write(STDOUT_FILENO, "Alej@ Super Shell$ ", 20);
		free(comand);
	}
	free(buffer);
	return (0);
}
