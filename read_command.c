#include "shell.h"

/**
<<<<<<< HEAD
 * read_command - function reads a line of input from user.
 * Return: pointer to the input string, or NULL if error
 */

char *read_command(void)
{
	char *input = NULL;
	size_t bufsize = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$"' 2);
	if (getline(&input, &bufsize, stdin) == -1)
	{
		free(input);
		return(NULL);
	}
	return (input);
}
