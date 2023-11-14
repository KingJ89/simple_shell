#include "shell.h"

/**
 * handle_comments - delete everythings that is preceded by '#'
 * @input: input string to handle comment
 */
void handle_comments(char *input)
{
	int i;

	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == '#' && (!i || input[i - 1] == ' '))
		{
			input[i] = '\0';
			break;
		}
	}
}

/**
 * replace_string - replace old string with new one
 * @old: address of old string
 * @new: new string
 */
void replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
}

/**
 * handle_variables - replaces variables in the command string
 * @command: full command
 * @status: last status code
 */
void handle_variables(char **command, int status)
{
	char *tmp = NULL;

	if (!command || !command[1])
		return;

	if (command[1] && (command[1][0] != '$' || !command[1][1]))
		return;

	if (_strcmp(command[1], "$?") == 0)
	{
		tmp = _itoa(status);
		replace_string(&command[1], _strdup(tmp));
	} else if (_strcmp(command[1], "$$") == 0)
	{
		tmp = _itoa(getpid());
		replace_string(&command[1], _strdup(tmp));
	} else
	{
		tmp = malloc(_strlen(command[1]) + 1);
		_strcpy(tmp, &command[1][1]);
		_strcat(tmp, "=");
		replace_string(&command[1], _getenv(tmp));
	}

	if (tmp)
		free(tmp), tmp = NULL;
}
