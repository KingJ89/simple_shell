#include "shell.h"

/**
 * find_path - finds command in the PATH string
 * @command: the command to find
 *
 * Return: full path of command, NULL if not exist
 */
char *find_path(char *command)
{
	char *env_path = NULL, *tmp_path = NULL, *command_path = NULL;
	struct stat st;

	if (!command)
		return (NULL);

	if (starts_with(command, "/"))
	{
		if (stat(command, &st) == 0)
			return (_strdup(command));
		return (NULL);
	}

	env_path = _getenv("PATH=");
	tmp_path = strtok(env_path, ":");
	while (tmp_path)
	{
		command_path = malloc(_strlen(tmp_path) + _strlen(command) + 2);
		if (command_path != NULL)
		{
			_strcpy(command_path, tmp_path);
			_strcat(command_path, "/");
			_strcat(command_path, command);
			if (stat(command_path, &st) == 0)
			{
				free(env_path), env_path = NULL;
				return (command_path);
			}
		}
		free(command_path), command_path = NULL;
		tmp_path = strtok(NULL, ":");
	}

	free(env_path), env_path = NULL;

	return (NULL);
}
