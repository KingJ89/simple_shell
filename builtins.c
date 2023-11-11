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

/**
 * print_env - prints the current environment
 * @command: command shell to print environment
 *
 * Return: 0 on success
 */
int print_env(char **command)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		_putchar('\n');
	}

	free_list(command);

	return (0);
}
