#include "shell.h"

/**
 * count_tokens - counts tokens in string
 * @input: string parameter
 *
 * Return: token count or 0 if non.
 */

int count_tokens(char *input)
{
	int count = 0;
	char *tmp = NULL, *token = NULL;

	tmp = _strdup(input);
	token = strtok(tmp, DELIM);
	if (token == NULL)
	{
		free(tmp), tmp = NULL;
		free(input), input = NULL;
		return (count);
	}

	while (token)
	{
		count++;
		token = strtok(NULL, DELIM);
	}

	free(tmp), tmp = NULL;

	return (count);
}

/**
 * find_command - Splits the input string into an array of tokens
 * @input: The input string to tokenize.
 *
 * Return: An array of tokens or NULL if tokenization fails.
*/
char **find_command(char *input)
{
	char **tokens = NULL, *token = NULL;
	int i = 0, count = 0;

	if (!input)
		return (NULL);

	count = count_tokens(input);
	if (count == 0)
		return (NULL);

	tokens = malloc(sizeof(char *) * (count + 1));
	if (tokens == NULL)
	{
		free(input), input = NULL;
		return (NULL);
	}

	token = strtok(input, DELIM);
	while (token)
	{
		tokens[i++] = _strdup(token);
		token = strtok(NULL, DELIM);
	}

	tokens[i] = NULL;
	free(input), input = NULL;

	return (tokens);
}
