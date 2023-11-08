#include "shell.h"

/**
 * count_tokens - conts the number of tokens in a string.
 * @input: this is the string parameter definition.
 * Return: number of tokens and 0 if no tokens
 */

int count_tokens(char *input)
{
	int count = 0;
	char *tmp = NULL, *token = NULL;

	tmp = _strdup(input);
	token = strtok(tmp, DELIM);
	if (token == NULL)

		free(tmp), tmp = NULL;
	free(input), input = NULL;
	return (count);

	while (token)
		count++;
	token = strtok(NULL, DELIM);

	free(tmp), tmp = NULL;
	return (count);
}
