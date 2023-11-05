#include "shell.h"

/**
 * main - functions entry point.
 * @ac: size of arguments.
 * @av: list of arguments.
 * Return: 0 on success>
 */

int main(int ac, char **av)
{
	char *input = NULL, **command = NULL;
	int status = 0;
	(void) ac;
	(void) av;

	while (1)
	{
		input = read_command();
		if (!input)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
	}
	return (0);
}
