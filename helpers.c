#include "shell.h"

/**
 * _strlen - function calculates the length of the string.
 * @s: number of bytes in the string.
 * Return: return i
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _strdup - function returns a pointer to a new string.
 * @str: duplicate of  the  string.
 * Return: return s
 */
char *_strdup(char *str)
{
	char *s;

	if (str == NULL)
	{
		return (NULL);
	}
	s = malloc(_strlen(str) + 1);
	if (s == NULL)
	{
		free(s);
		return (NULL);
	}
	_strcpy(s, str);
	return (s);
}

/**
 * _strcat - functions return a pointer to the resulting string dest.
 * @dest: the resulting string in dest is always null-terminated.
 * @src: function appends the src string to the dest string.
 * Return: return dest
 */
char *_strcat(char *dest, char *src)
{
	int i, len;

	len = _strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}

/**
 * _strcpy - function copies the string pointed to by src.
 * @src: including the terminating null byte ('\0').
 * @dest: to the buffer pointed to by dest.
 * Return: return dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
