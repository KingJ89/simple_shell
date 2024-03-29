#include "shell.h"

/**
 * read_command - read input command using getline
 *
 * Return: full string command
 */
char *read_command(void)
{
	char *line = NULL;
	size_t linecap = 0;
	ssize_t linelen;

	if (isatty(STDIN_FILENO))
		_puts("$ ", 1);

	linelen = getline(&line, &linecap, stdin);
	if (linelen == -1)
	{
		free(line), line = NULL;
		return (NULL);
	}
	handle_comments(line);

	return (line);
}
