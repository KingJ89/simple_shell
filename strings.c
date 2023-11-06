#include "shell.h"

/**
 * _strdup - duplicat a string given
 * @str: string parameter
 *
 * Return: pointer to the duplicat string
 */
char *_strdup(char *str)
{
	int len = 0;
	char *res;

	if (str == NULL)
		return (NULL);

	while (*str++)
		len++;

	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);

	for (len++; len--;)
		res[len] = *--str;

	return (res);
}
