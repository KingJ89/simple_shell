#include "shell.h"

/**
 * count_tokens - couts tokens in string
 * @input: string parameter
 * Return: token count or 0 if non.
 */

int count_tokens(char *input)
{
	int  count = 0;
	char tmp = NULL, *token = NULL;

	tmp = strdup(input);
	char *tmp = strtok(tmp, DELIM);

	if (token == NULL
		free(tmp), tmp = NULL;
		free(input), input = NULL;
		return (count);

		while (token)
		count++;
		token = strtok(NULL, DELIM);

		free(tmp), tmp = NULL;
		return (count);
}


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
	return (NULL);

	token = strtok(input, DELIM);
	while (token)

		tokens[i++] = _strdup(token);
	token = strtok(NULL, DELIM);

	tokens[i] = NULL;
	free(input), input = NULL;

	return (tokens);
}
