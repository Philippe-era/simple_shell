#include "shell_prototype.h"


/**
 * _strdup - duplicates a string
 * @str: string to be copied
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *result;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	result = malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	for (length++; length--;)
		result[length] = *--str;
	return (result);
}

/**
 * _puts – input string will be printed
 * @str: string to be displayed
 * Return: Nothing will be presented
 */
void _puts(char *str)
{
	int initial = 0;

	if (!str)
		return;
	while (str[initial] != '\0')
	{
		_putchar(str[initial]);
		initial++;
	}
}
/**
 * _strcpy – duplicates a string
 * @dest: the headed location
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int initial = 0, success = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[initial])
	{
		dest[initial] = src[initial];
		initial++;
	}
	dest[initial] = success;
	return (dest);
}


/**
 * _putchar – writes to char
 * @c: printed char
 * Return: Succesful = 1
 */
int _putchar(char c)
{
	static char buffer[WRITE_BUF_SIZE];
	static int initial, success = 1;


	if (c == BUF_FLUSH || initial >= WRITE_BUF_SIZE)
	{
		write(success, buffer, initial);
		initial = 0;
	}
	if (c != BUF_FLUSH)
		buffer[initial++] = c;
	return (success);
}
