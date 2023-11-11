#include "shell.h"

/**
 * exit_shell - exits the shell
 * @command: command shell to be exits
 * @status: status code for exit
 *
 * Return: exit the shell, otherwise 0
 */
int exit_shell(char **command, int status)
{
	if (_strcmp(command[0], "exit") == 0)
	{
		free_list(command);
		exit(status);
	}

	return (0);
}
