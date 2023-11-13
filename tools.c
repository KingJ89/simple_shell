#include "shell.h"

/**
 * _abs - computes the absolute value of an integer
 * for a parametre given
 * @n: integer parametere give
 * Return: the absolute value of the parameter
 */
int _abs(int n)
{
	if (n > 0 || n == 0)
	{
		return (n);
	}

	return (n * (-1));
}

/**
 * _atoi - convert string to an int
 * @s: pointer char parameter
 *
 * Return: number converted, 0 if no number digit found
 */
int _atoi(char *s)
{
	int i, res = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		res = res * 10 + s[i] - '0';
	}

	return (res);
}

/**
 * positif_digits - check if string has only positif digits
 * @s: string parameter
 *
 * Return: converted string to integer, otherwise -1
 */
int positif_digits(char *s)
{
	int i;

	if (!s)
		return (-1);

	for (i = 0; s[i]; i++)
		if (s[i] < '0' || s[i] > '9')
			return (-1);

	return (_atoi(s));
}

/**
 * handle_comments - delete everythings that is preceded by '#'
 * @input: input string to handle comment
 */
void handle_comments(char *input)
{
	int i;

	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == '#' && (!i || input[i - 1] == ' '))
		{
			input[i] = '\0';
			break;
		}
	}
}
