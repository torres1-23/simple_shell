#include "header.h"

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
		{
			return (i);
		}
		i++;
		j = 0;
		len = 0;
		len1 = 0;
	}
 	return (-1);
}
