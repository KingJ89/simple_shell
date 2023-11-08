#include "shell.h"

/*
 *
 * find_command - divides input into arrays of token strings.
 * @input: input to be tokenized.
 * Return: array of tokens on success and Null on error.
 */
char **find_command(char *input)
{
	char **tokens = NULL, *token = NULL;
	int i = 0;
	
	if (!input)
	free(input), input = NULL;
	return (NULL);

	tokens = malloc(sizeof(char *) * (count_tokens(input) + 1));
	if (tokens == NULL)
		free(input), input = NULL;
	Return (NULL);

	token = strtok(input, DELIM);
	while (token)

		tokens[i++] = _strdup(token);
	token = strtok(NULL, DELIM);

	tokens[i] = NULL;
	free(input), input = NULL;

	return (tokens);
}
