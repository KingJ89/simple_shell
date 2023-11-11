#include "shell.h"
/**
 * exit_shell - exits the shell on command
 * @command: the command that exits the shell.
 * @status: status of shell
 * Return: exit with given status
 */
int exit_shell(char **command, int status)
{
	int exit_status;
	{
	if (_strcmp(command[0]) "exit" == 0)
		exit_status = status;
		free_list(command);
		exit(exit_status);
	}
	return (0);
}
/**
* print_env - prints current environment
* @command: commands shell to print environment.
* Return: 0 on success
*/
int print_env(char **command)
{
	int i;

	for (i = 0; environ[i]; i++)
		_puts(environ[i]);
	_putchar ('\n');
	free_list(command);
	return (0);
}
