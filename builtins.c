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

	exit_status = 0;
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

	return (exit_status);
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

/**
 * exec_chdir - return value of chdir
 * @input: argument of cd command
 *
 * Return: value of chdir
 */
int exec_chdir(char *input)
{
	char *path = NULL;
	int res = 0;

	if (!input || strcmp(input, "~") == 0)
		path = _getenv("HOME=");
	else if (strcmp(input, "-") == 0)
	{
		path = _getenv("OLDPWD=");
		_puts(path), _putchar('\n');
	}
	else
		res = chdir(input);

	if (path)
	{
		res = chdir(path);
		free(path), path = NULL;
	}

	return (res);
}

/**
 * handle_cd - change the current directory of the process
 * @command: full command
 * @av: argument string for shell command
 * @count: index of error line
 *
 * Return: Always 0
 */
int handle_cd(char **command, char **av, int count)
{
	char buf[1024], *tmp = NULL, *msg = "can't cd to ";
	int value, exit_status = 0;

	value = exec_chdir(command[1]);
	if (value == -1)
	{
		tmp = malloc(_strlen(msg) + _strlen(command[1]) + 1);
		_strcpy(tmp, msg);
		_strcat(tmp, command[1]);
		print_error(av[0], count, command[0], tmp, NULL);
		exit_status = STAT_ILLEGAL_NUMBER;
	}
	else
	{
		tmp = _getenv("PWD=");
		setenv("OLDPWD", tmp, 1);
		setenv("PWD", getcwd(buf, 1024), 1);
	}

	free(tmp), tmp = NULL;
	free_list(command);

	return (exit_status);
}
