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
 */
void _cexit(char *str)
{
	int i = 0, j = 0, k = 0, l, digi;
	char dig[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'};
	char num[255 * 4], *space = " ", *copy;

	copy = delspace(str, 5);
	if (copy[i])
	{
		for (i = 0; copy[i]; i++)
		{
			j = 0;
			while (dig[j])
			{
				if (copy[i] == dig[j])
				{
					num[k++] = copy[i];
					break;
				}
				j++;
			}
			if (copy[i] == space[0])
			{
				for (l = i; copy[l]; l++)
				{
					if (copy[l] != space[0] || !copy[l])
					{
						write(STDOUT_FILENO, "Too many arguments\n", 20);
						return;
					}
				}
			}
			if (j == 10)
				message_exit(0, copy, digi);
		}
		digi = _atoi(num);
		if (digi > 0 && digi <= 255)
			message_exit(1, copy, digi);
	}
	else
		message_exit(2, copy, digi);
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
 * delspace - Function that deletas space before find a character
 * @str: string to remove the space
 * @index: index to star to remove
 * Return: return a pointer to the new string starting with a caracter o null
 */
char *delspace(char *str, int index)
{
	char *copy, *space = " ";
	int i = index, j, len = 0;

	while (str[len++])
	;
	copy = malloc(sizeof(char) * len + 1);
	while (str[i])
	{
		if (str[i] != space[0])
			break;
		i++;
	}
	for (j = 0; j <= len; j++)
		copy[j] = str[i++];
	return (copy);
}
