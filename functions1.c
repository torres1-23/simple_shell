#include "shell.h"

/**
 * _getenv - function that emulate getenv.
 * @name: name of the enviorment variable.
 * Return: pointer to the value of the variable.
 */

char *_getenv(const char *name)
{
	int index, i = 0;
	char *tmp, **tmp2, *ret = NULL;

	if (name)
	{
		index = _getposition(name);
		if (index >= 0)
		{
			tmp = _strdup(environ[index]);
			tmp2 = call_strtok(tmp, "=");
			ret = _strdup(tmp2[1]);
		}
		else
			return (NULL);
		while (tmp2[i])
		{
			free(tmp2[i]);
			i++;
		}
		free(tmp2);
		free(tmp);
	}
	return (ret);
}

/**
 * _getposition - gets position of desired variable.
 * @name: name of the environment variable.
 * Return: position of desired variable.
 */

int _getposition(const char *name)
{
	int i = 0, j = 0, len = 0, len1 = 0;

	while (environ && environ[i])
	{
		while (environ[i][len] != '=')
			len++;
		len1 = len;
		while (len > 0)
		{
			if (environ[i][j] == name[j])
				j++;
			else
				break;
			len--;
		}
		if (len1 == j && j != 0)
			return (i);
		i++;
		j = 0;
		len = 0;
		len1 = 0;
	}
	return (-1);
}

/**
 * _cexit - Function that cause normal process termination
 * @str: exit command with or without arguments
 * @buffer: buffer
 * @exe: name of executable.
 * @cont: number of commands written.
 * @status1: status to return on exit
 */

void _cexit(char *exe, int cont, char *str, char *buffer, int status1, char *copy)
{
	int i = 5, j = 0, k = 0, digi = 0, fg = 0;
	char dig[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'};
	char num[1020], *space = " ", *strc;

	strc = delspace(str, copy, 5);
	printf("copy = %s \n", copy);
	if (strc[i])
	{
		for (i = 0; strc[i]; i++)
		{
			j = 0;
			while (dig[j])
			{
				if (strc[i] == dig[j])
				{
					num[k++] = strc[i];
					break;
				}
				if (strc[i] == space[0])
				{
					fg = 1;
					break;
				}
				j++;
			}
			if (j == 10)
			{
				message_exit(0, digi, strc, str, buffer, exe, cont, 0);
				return;
			}
			if (fg == 1)
				break;
		}
		digi = _atoi(num);
		if (digi > 0 && digi <= 255)
			message_exit(1, digi, strc, str, buffer, exe, cont, 0);
		else
			message_exit(3, digi, strc, str, buffer, exe, cont, 0);
	}
	else
		message_exit(4, digi, strc, str, buffer, exe, cont, status1);
}

/**
 * _atoi - convert a string to an integer.
 * @s: string to convert
 *
 * Return: the string converted to int.
 */

int _atoi(char *s)
{
	unsigned int i = 0, length = 0, sign = 0, sum = 0;
	unsigned int init, finish, d, num;

	while (s[length] != '\0')
		length++;
	if (length == 0)
		return (0);
	for (i = 0; i < length; i++)
	{
		if (s[i] == '-')
			sign++;
		if (s[i] >= 48 && s[i] <= 57)
		{
			init = i;
			break;
		}
	}
	for (; i < length; i++)
	{
		if (s[i] < 48 || s[i] > 57)
		{
			break;
		}
	}
	finish = i - 1;
	for (; init <= finish; init++)
	{
		num = 1;
		d = s[init] - '0';
		for (i = 0; i < finish - init ; i++)
			num = num * 10;
		num = num * d;
		sum = num + sum;
	}
	if (sign % 2 == 1)
		sum = -sum;
	return (sum);
}
/**
 * delspace - Function that deletes space before find a character
 * @str: string to remove the space
 * @index: index to star to remove
 * Return: return a pointer to the new string starting with a caracter o null
 */
char *delspace(char *str, char *copy, int index)
{
	char *space = " ";
	int i = index, j = 0, len = 0;

	if (!str)
		return (NULL);
	while (str[len++])
	;
	while (str[i])
	{
		if (str[i] != space[0])
			break;
		i++;
	}
	for (j = 0; str[i]; j++)
		copy[j] = str[i++];
	copy[j] = '\0';
	return (copy);
}
