#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main
{
	pid_t child1 = fork();
	char *args[] = {"/bin/ls", "-l", "/tmp"};

	if (child1 == 0)
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
	}
}
