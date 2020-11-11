#include <stdio.h>
#include <string.h>

int main(int __attribute__((unused))ac, char *av[])
{
	char *token;

	token = strtok(av[1], " ");
	while (token)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
	return (0);
}
