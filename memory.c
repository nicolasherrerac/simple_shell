#include "shell.h"
/**
 * _memset - Fuction that fill bytes with the number of costant.
 * @s: Starting address of memory to be filled.
 * @b: Value to be filled.
 * @n: Number of bytes to be filled starting from ptr to be filled.
 * Return: s.
 */
char *_memset(char *s, int b, unsigned int n)
{
	int i = 0;

	while (n > 0)
	{
		s[i] = b;
		i++;
		n--;
	}
	return (s);
}
