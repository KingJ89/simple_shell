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
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);

	return ((char *)haystack);
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
