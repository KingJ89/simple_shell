#include "shell.h"

/**
 * _getenv - gets the value of an environ variable
 * @name_env: environ string to search with
 *
 * Return: value of environ
 */
char *_getenv(char *name_env)
{
	char *tmp = NULL, *env = NULL, *path = NULL,
	     *tmp_name = NULL, *name = NULL, *tmp_env = NULL;
	int i;

	tmp_name = _strdup(name_env);
	name = strtok(tmp_name, "=");
	for (i = 0; environ[i]; i++)
	{
		tmp_env = _strdup(environ[i]);
		tmp = strtok(tmp_env, "=");
		if (_strcmp(tmp, name) == 0)
		{
			if (tmp)
				path = strtok(NULL, "=");

			env = _strdup(path);
			free(tmp_name), tmp_name = NULL;
			free(tmp_env), tmp_env = NULL;
			return (env);
		}

		free(tmp_env), tmp_env = NULL;
	}

	free(tmp_name), tmp_name = NULL;

	return (NULL);
}
