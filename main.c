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
	int status = 0;
	(void) ac;

	while (1)
	{
		input = read_command();
		if (!input)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		command = find_command(input);
		if (!command)
			continue;

		status = execute_command(command, av);
	}

	return (status);
}
