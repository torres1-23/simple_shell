#include "shell.h"
/**
 * main - Entry point
 * Simple shell written by Alejandro and Alejandra
 * Return: 0 in success.
 */
int main(void)
{
	char *buffer = NULL, **arr = NULL, *comand = NULL;
	size_t buffersize = 0;
	ssize_t numc = 0;
	int i = 0, x = 1;

	while (x == 1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			write(STDOUT_FILENO, "Alej@ Super Shell$ ", 20);
			x = 1;
		}
		if (isatty(STDIN_FILENO) == 0)
			x = 0;
		numc = getline(&buffer, &buffersize, stdin);
		if (numc != -1)
		{
			buffer[numc - 1] = '\0';
			comand = delspace(buffer, 0);
			built_in(comand, buffer);
			if (numc != 1 && comand[0])
			{
				arr = call_strtok(comand, " ");
				execute(arr, comand, buffer);
				i = 0;
				while (arr[i])
					free(arr[i++]);
				free(arr);
			}
			free(comand);
		}
		else
			break;
	}
	free(buffer);
	return (0);
}
