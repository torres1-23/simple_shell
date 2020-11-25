#include "shell.h"

/**
 * main - Entry point
 * Simple shell written by Alejandro and Alejandra
 * @argc: number of arguments.
 * @argv: array of pointers to each argument.
 * Return: 0 in success.
 */

int main(int argc __attribute__((unused)), char **argv)
{
	char *buffer = NULL, **arr = NULL, *comand = NULL, copy[1024] = {'\0'};
	size_t buffersize = 0;
	ssize_t numc = 0;
	int status = 0, status1 = 0, val_isatty;
	static int cont = 1;

	while (1)
	{
		signal(SIGINT, handle_sigint);
		val_isatty = isatty(STDIN_FILENO);
		if (val_isatty == 1)
			write(STDOUT_FILENO, "Alej@ Super Shell$ ", 20);
		numc = getline(&buffer, &buffersize, stdin);
		if (numc == EOF)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(STDOUT_FILENO, "\n", 2);
			break;
		}
		buffer[numc - 1] = '\0';
		comand = delspace(buffer, copy, 0);
		status = built_in(argv[0], cont, comand, buffer, status1, copy);
		if (status == 1)
		{
			if (numc != 1 && comand[0])
			{
				arr = call_strtok(comand, " ");
				status1 = execute(argv[0], cont, arr, buffer);
				free_bidimensional(arr);
			}
		}
		cont++;
	}
	free(buffer);
	if ((val_isatty == 1) && (numc == 0))
		free_bidimensional(environ);
	if (status != 1)
		return (status);
	return (status1);
}
