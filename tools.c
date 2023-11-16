#include "shell.h"

/**
 * _abs - computes the absolute value of an integer
 * for a parametre given
 * @n: integer parametere given
 *
 * Return: the absolute value of the parameter
 */
int _abs(int n)
{
	if (n > 0 || n == 0)
		return (n);

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
		res = (res * 10) + s[i] - '0';
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
 * _itoa - convert integer number to string
 * @nbr: integer parameter
 *
 * Return: string number
 */
char *_itoa(int nbr)
{
	char buf[10], aux;
	int i = 0, j = 0;

	if (nbr == 0)
		buf[i++] = '0';
	else
	{
		do {
			buf[i++] = (nbr % 10) + '0';
			nbr /= 10;
		} while (nbr != 0);
	}

	buf[i] = '\0';
	while (j < (i - 1))
	{
		aux = buf[j];
		buf[j] = buf[i - 1];
		buf[i - 1] = aux;
		j++;
		i--;
	}

	return (_strdup(buf));
}
