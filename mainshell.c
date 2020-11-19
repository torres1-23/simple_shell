#include "shell.h"
/**
 * main - Entry point
 * Simple shell written by Alejandro and Alejandra
 * Return: 0 in success.
 */
int main(void)
{
	char *buffer = NULL, **arr = NULL, *comand = NULL, *space = " ", *exit = "exit";
	size_t buffersize = 0;
	ssize_t numc = 0;
	int i = 0, j = 0;

	write(STDOUT_FILENO, "Alej@ Super Shell$ ", 20);
	while ((numc = getline(&buffer, &buffersize, stdin)) != -1)
	{
		i = 0;
		j = 0;
		buffer[numc - 1] = '\0';
		comand = delspace(buffer, 0);
		j = 0;
		while (comand[j] == exit[j])
			j++;
		if ((j == 5) || ((j == 4) && (comand[j] == space[0])))
			_cexit(comand);	
		if (numc != 1 && comand[0])
		{
			arr = call_strtok(comand, " ");
			execute(arr, comand, buffer);
			i = 0;
			while (arr[i])
				free(arr[i++]);
			free(arr);
		}
		write(STDOUT_FILENO, "Alej@ Super Shell$ ", 20);
		free(comand);
	}
	free(buffer);
	return (0);
}
