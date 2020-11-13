#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <dirent.h>


int main (int argc, char *argv[])
{
	char cwd[PATH_MAX];
	struct stat dir_stat;
	int i = 1;

	/*store current working directory in current path*/
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return (1);

	if (argc < 2)
	{
		printf("Usage: %s filename ...\n", argv[0]);
		return (1);
	}
	while (argv[i])
	{
		printf("%s:", argv[i]);
		if (stat(argv[i], &dir_stat) == 0)
		{
			printf("Found on directory %s\n", cwd);
		}
		else
		{
			printf("Not found on directory %s\n", cwd);
		}
		i++;
	}
	return (0);
}
