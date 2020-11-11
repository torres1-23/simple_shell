#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *buffer = NULL;
	size_t buffersize = 0;
	ssize_t numc = 0;

	printf("$ ");
	while ((numc = getline(&buffer, &buffersize, stdin)) != -1)
	{
		printf("\n%s\n", buffer);
		printf("$ ");
	}
	free (buffer);
	return (0);
}
