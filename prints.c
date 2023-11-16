#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * @stdtype: stream value
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c, int stdtype)
{
	return (write(stdtype, &c, 1));
}

/**
 *_puts - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str, int stdtype)
{
	int i = 0;

	if (!str)
		return;

	while (str[i] != '\0')
	{
		_putchar(str[i], stdtype);
		i++;
	}
}

/**
 * print_number - print a number
 * @n: integer parameter
 */
void print_number(int n)
{
	if (n < 0)
	{
		n = _abs(n);
		_putchar('-', 1);
	}

	if (n >= 10)
	{
		print_number(n / 10);
	}

	_putchar('0' + (n % 10), 1);
}

/**
 * print_error - prints an error message
 * @shell_name: string contain program name
 * @count: the error count
 * @cmd: string containing specified error
 * @msg: message error to display
 * @arg: illegal argument
 *
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error(char *shell_name, int count, char *cmd, char *msg, char *arg)
{
	_puts(shell_name, 2);
	_puts(": ", 2);
	print_number(count);
	_puts(": ", 2);
	_puts(cmd, 2);
	_puts(": ", 2);
	_puts(msg, 2);
	if (arg)
	{
		_puts(": ", 2);
		_puts(arg, 2);
	}
	_putchar('\n', 2);
}
