#include "shell.h"

/**
 * _strdup - duplicat a string given
 * @str: string parameter
 *
 * Return: pointer to the duplicat string
 */
char *_strdup(char *str)
{
	int len = 0;
	char *res;

	if (str == NULL)
		return (NULL);

	while (*str++)
		len++;

	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);

	for (len++; len--;)
		res[len] = *--str;

	return (res);
}

/**
 * _strlen - returns the length of a string
 * @str: the string get length
 *
 * Return: integer length of string
 */
int _strlen(char *str)
{
	int i = 0;

	if (!str)
		return (0);

	while (*str++)
		i++;

	return (i);
}

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = 0;

	return (dest);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

/**
 * _strcmp - performs lexicographic comparaison of two strangs
 * @s1: first string
 * @s2: second string
 *
 * Return: negative if s1 < s2, positif if s1 > s2, 0 if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);

		s1++;
		s2++;
	}

	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}
