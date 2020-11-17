#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <dirent.h>


int main (int argc, char *argv[])
{
	struct stat dir_stat;
	int i = 2, j = 0, len = 0;
	char *cmp = "_which";

	/*store current working directory in current path*/
	if (argc < 3)
	{
		printf("Usage: %s _which filename ...\n", argv[0]);
		return (-1);
	}
	while (argv[1][len])
		len++;
	while (argv[1][j])
	{
		if (argv[1][j] == cmp[j])
			j++;
		else
			break;
	}
	if (len == j)
	{
		while (argv[i])
		{
			if (stat(argv[i], &dir_stat) == 0)
			{
				printf("%s\n", argv[i]);
			}
			else
			{
				printf("Not found\n");
			}
			i++;
		}
	}
	return (0);
}
