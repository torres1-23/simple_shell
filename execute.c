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
	int status, stat = 0, stats;
	pid_t childn;
	char *path;

	(void)cont;
	(void)exe;
	childn = fork();
	if (childn == 0)
	{
		if ((args[0][0] == '/' && args[0][1] != '/') ||
		(args[0][0] == '.' && args[0][1] == '/'))
		{
			stat = execve(args[0], args, environ);
		}
		else
		{
			path = find_path(args[0]);
			args[0] = _strdup(path);
			stat = execve(args[0], args, environ);
		}
		free_stuff(args, b);
		err_hd(stat, path);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			stats = WEXITSTATUS(status);
			if (stats == 126)
				message_error(0, exe, cont, args[0]);
			else if (stats == 127)
				message_error(1, exe, cont, args[0]);
		}
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
	char *name = "PATH", *route, *colon = ":", *dot = ".";
	char *getenvp, **directory;
	int i = 0;
	struct stat dir_stat;

	getenvp = _getenv(name);
	if (getenvp[0] == colon[0])
	{
		route = str_concatdot(dot, getenvp);
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

/**
 * str_concatdot - concatenates string.
 * @s1: string 1.
 * @s2: string 2.
 * Return: void
 */

char *str_concatdot(char *s1, char *s2)
{
	int i = 0, j = 0, k, l;
	char *con;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	con = malloc(sizeof(char) * (i + j + 1));
	if (con == 0)
		return (NULL);
	for (k = 0; k < i; k++)
		con[k] = s1[k];
	for (l = 0; l < j; l++)
		con[k++] = s2[l];
	con[k] = '\0';
	return (con);
}

/**
 * err_hd - handle child errors.
 * @stat: stat.
 * @path: path.
 */

void err_hd(int stat, char *path)
{
	if (stat == 1)
		exit(0);
	if (errno == EACCES)
		exit(126);
	else if (errno == ENOENT || !path)
		exit(127);
	else
		exit(2);
}
