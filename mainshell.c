#include "shell.h"
/**
 * main - Entry point
 * Simple shell written by Alejandro and Alejandra
 * Return: 0 in success.
 */
int main(void)
{
	char *buffer = NULL, **arr, *comand = NULL, *space = " ";
	size_t buffersize = 0;
	ssize_t numc = 0;
	int i = 0, j = 0;

	write(STDOUT_FILENO, "Alej@ Super Shell$ ", 20);
	while ((numc = getline(&buffer, &buffersize, stdin)) != -1)
	{
		i = 0;
		j = 0;
		comand = malloc(sizeof(char) * (numc + 1));
		buffer[numc - 1] = '\0';
		while(buffer[i])
		{
			if(buffer[i] != space[0])
				comand[j++] = buffer[i];
			i++;
		}
		comand[j] = '\0';
		if(numc != 1 && comand[0])
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
		free(comand);
		buffer = NULL;
		write(STDOUT_FILENO, "Alej@ Super Shell$ ", 20);
	}
	free (buffer);
	return (0);
}
