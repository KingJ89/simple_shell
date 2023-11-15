#include "shell.h"

/**
 * main - entry point
 * @ac: size of arguments
 * @av: list of arguments
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	char *input = NULL, **command = NULL;
	int status = 0, count = 0;
	(void) ac;

	while (1)
	{
		input = read_command();
		if (!input)
		{
			if (isatty(STDIN_FILENO))
				_putchar('\n');
			break;
		}
		count++;

		command = find_command(input);
		handle_variables(command, status);
		if (!command)
			continue;

		if (_strcmp(command[0], "cd") == 0)
			status = handle_cd(command, av, count);
		else
		{
			status = exit_shell(command, status, av, count);
			if (status == 0)
			{
				if (_strcmp(command[0], "env") == 0)
				{
					status = print_env(command);
				} else
					status = execute_command(command, av, count);
			}
		}
	}

	return (status);
}
