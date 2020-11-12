#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int i;
	pid_t childn, parent;
	char *args[] = {"/bin/ls", "-l", "/tmp/", NULL};

	for (i = 0; i < 5; i++)
	{
		childn = fork();
		if (childn == -1)
		{
			perror("Error");
			return (1);
		}
		if (childn == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error");
				return (1);
			}
		}
		else
		{
			wait(NULL);
			printf("then of number %d \n", (i + 1));
		}
		parent = getppid();
		childn = getpid();
		printf("Id parent %d\n", parent);
		printf("Id child %d\n", childn);
	}
	return (0);
}
