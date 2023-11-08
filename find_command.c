#include "shell.h"

/**
 * find_command - divides input into arrays of token strings.
 * @input: input to be tokenized.
 * Return: array of tokens on success and Null on error.
 */
char **find_command(char *input)
{
	size_t num_tokens = 0;
	char **tokens = NULL;

	num_tokens = count_tokens(input);

	if (num_tokens == 0)
		return(NULL)

			tokens = malloc(sizeof(char *) * (num_tokens + 1));
	if (!tokens)
		free(input), input = Null;
	return (NULL);

	tokenize(tokens, input);
	return (tokens);
}
