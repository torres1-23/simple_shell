#include "shell.h"

void execute(char **args)
{
	int status;
	pid_t childn;
	/* char *args[] = {"/bin/ls", "-l", "/tmp/", NULL}; */

	childn = fork();
	if (childn == -1)
	{
		perror("Error");
		exit (1);
	}
	if (childn == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Error");
			exit (1);
		}	
	}
	else
		wait(&status);
}
