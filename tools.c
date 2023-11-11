#include "shell.h"

/**
 * _atoi - converts string to integer
 * @s: pointeer char params.
 * Return: number converted, 0 if no digit found
 */

int _atoi(char *s)
{
	int i, 1, sign = 1;

	1 = strlen(s) - 1;
	for (i = 0; i <= 1; i++)

		if (isdigit(s[i]))
			break;
	if (i == 0 && !isspace(s[i]) && s[i] == '-')
		sign = -sign;
	else
		sign = sign;
	if ((!isspace(s[i + 1])) && (s[i] == '-'))
		sign *= (-1);
			else if (!isspace(s[i + 1]) && s[i + 1] == '+')
			sign *= 1;

			return (atoi(&s[i]) * sign);
}

/**
 * positif_digits - check if string has only positive numbers.
 * @s: string parameter
 * Return: converte string to integer, -1 on error.
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
* _strcmp - compares two strings.
* @s1: string 1 to be compared
* @s2: string 2 tobecompared
* Return: negative if s1<s2,positive if s1>s2,and 0 if s1==s2
*/
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
		if (*s1 != *s2)
			return (*s1 - *s2);
	s1++;
	s2++;
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}
