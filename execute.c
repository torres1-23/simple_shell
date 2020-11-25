#include "shell.h"

/**
 * execute - function that execute the arguments received
 * @args: arguments
 * @b: buffer
 * @exe: name of executable.
 * @cont: number of commands written.
 * Return: integer Status
 */

int execute(char *exe, int cont, char **args, char *b)
{
	int status, i = 0, stat = 0, stats;
	pid_t childn;
	char *path;

	path = find_path(args[0]);
	childn = fork();
	if (childn == -1)
	{
		perror("Error");
		while (args[i])
			free(args[i++]);
		free(args);
		exit(EXIT_FAILURE);
	}
	if (childn == 0)
	{
		path = find_path(args[0]);
		/*if ((args[0][0] == '/' && args[0][1] != '/') ||
		(args[0][0] == '.' && args[0][1] == '/'))
		{
			stat = execve(args[0], args, environ);
			if (stat == 1)
				exit(stat);
		}usar un stat antes de fork para asegurarme antes*/
		if (path)
		{
			args[0] = _strdup(path);
			stat = execve(args[0], args, environ);
			exit(stat);
		}
		message_exit(2, 0, args[0], NULL, exe, cont, 0);
		free_stuff(args, b);
		exit(127);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			stats = WEXITSTATUS(status);
	}
	return (stats);
}

/**
 * find_path - function that find the route of the identifier.
 * @exname: name of executable.
 * Return: pointer to the route.
 */

char *find_path(char *exname)
{
	char *name = "PATH", *route, *colon = ":", *exe = "./";
	char *getenvp, **directory;
	int i = 0;
	struct stat dir_stat;

	if (stat(exname, &dir_stat) == 0)
		return (exname);
	getenvp = _getenv(name);
	if (getenvp[0] == colon[0])
	{
		getenvp = malloc(sizeof(char) * 3);
		getenvp = ".";
		route = str_concat(getenvp, exname);
		return (route);
	}
	if (getenvp && getenvp[0])
	{
		directory = call_strtok(getenvp, ":");
		for (i = 0; directory[i]; i++)
		{
			route = str_concat(directory[i], exname);
			if (stat(route, &dir_stat) == 0)
				return (route);
			free(route);
		}
		i = 0;
		while (directory[i])
			free(directory[i++]);
		free(directory);
	}
	free(getenvp);
	return (NULL);
}

/**
 * handle_sigint - handles signal inturupt from ctrl+c
 * @i: value from main
 * Return: void
 */

void handle_sigint(int i)
{
	(void)i;
	write(STDOUT_FILENO, "\n", 2);
	write(STDOUT_FILENO, "Alej@ Super Shell$ ", 20);
}