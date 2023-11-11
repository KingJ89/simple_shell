#include "shell.h"

/**
 * exit_shell - exits the shell
 * @command: command shell to be exits
 * @status: status code for exit
 * @av: argument string for shell command
 * @count: index of error line
 *
 * Return: exit the shell, otherwise 0
 */
int exit_shell(char **command, int status, char **av, int count)
{
	int exit_status;

	if (_strcmp(command[0], "exit") == 0)
	{
		exit_status = status;
		if (command[1])
		{
			exit_status = positif_digits(command[1]);
			if (exit_status == -1)
			{
				exit_status = STAT_ILLEGAL_NUMBER;
				print_error(av[0], count, command[0], "Illegal number", command[1]);
				free_list(command);
				return (exit_status);
			}
		}

		free_list(command);
		exit(exit_status);
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
