#include "shell.h"

/**
 * find_command - return one command from an input
 * @input: input string parameter
 *
 * Return: one command, NULL if it fails.
 */
char **find_command(char *input)
{
	char *tmp = NULL, *token = NULL, **cmd = NULL;

	if (!input)
		return (NULL);

	tmp = _strdup(input);
	token = strtok(tmp, DELIM);
	if (token == NULL)
	{
		free(tmp), tmp = NULL;
		free(input), input = NULL;
		return (NULL);
	}

	cmd = malloc(sizeof(char *) * 2);
	if (!cmd)
	{
		free(input), input = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}

	token = strtok(input, "\n");
	cmd[0] = _strdup(token);
	free(input), input = NULL;
	free(tmp), tmp = NULL;
	cmd[1] = NULL;

	return (cmd);
}
