#include "shell.h"

int main(void)
{
	char *buffer = NULL, **arr;
	size_t buffersize = 0;
	ssize_t numc = 0;
	int i = 0;

	write(STDOUT_FILENO, "Alej@ Super Shell$ ", 20);
	while ((numc = getline(&buffer, &buffersize, stdin)) != -1)
	{
		buffer[numc - 1] = '\0';
		arr = call_strtok(buffer);
		execute(arr);
		write(STDOUT_FILENO, "Alej@ Super Shell$ ", 20);
	}
	while (arr[i]) 
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	free (buffer);
	return (0);
}
