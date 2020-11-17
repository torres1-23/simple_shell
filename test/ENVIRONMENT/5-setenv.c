#include "header.h"

int _setenv(const char *name, const char *value, int overwrite)
{
	int index, j = 0, i = 0, k, l = 0;

	if (_getposition(name) >= 0 && overwrite == 0)
		return (0);

	if ((index = _getposition(name)) >= 0 && overwrite != 0)
	{
		for (j = 0; environ[index][j] != '\0'; j++)
			environ[index][j] = '\0';

		for (j = 0; name[j] != '\0'; j++)
			;

		for (i = 0; i < j; i++)
			environ[index][i] = name[i];

		environ[index][i++] = '=';

		for (j = 0; value[j] != '\0'; j++)
			;

		for (k = 0; k < j; k++)
			environ[index][i++] = value[k];

		environ[index][i] = '\0';
	}

	if (_getposition(name) < 0)
	{
		while (environ[l])
			l++;
		printf("position : %d", l);

                for (j = 0; name[j] != '\0'; j++)
                        ;

                for (i = 0; i < j; i++)
                        environ[l][i] = name[i];

                environ[l][i++] = '=';

                for (j = 0; value[j] != '\0'; j++)
                        ;

                for (k = 0; k < j; k++)
                        environ[l][i++] = value[k];

                environ[l][i] = '\0';
	}
	return(0);
}
