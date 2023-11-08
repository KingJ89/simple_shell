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
