#include <stdio.h>

int main (int __attribute__((unused))argc, char *argv[])
{
	int i = 0;

	while (argv[i])
	{
		printf("%s\n", argv[i]);
		i++;
	}
	return (0);
}
