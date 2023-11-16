#include "shell.h"

/**
 * _getenv - gets the value of an environ variable
 * @name: environ string to search with
 *
 * Return: value of environ
 */
char *_getenv(char *name)
{
	char *tmp = NULL, *env = NULL, *path = NULL;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		path = starts_with(tmp, name);
		if (path)
		{
			path++;
			env = _strdup(path);
			free(tmp), tmp = NULL;
			return (env);
		}

		free(tmp), tmp = NULL;
	}

	return (NULL);
}
