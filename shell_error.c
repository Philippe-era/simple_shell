#include "shell_prototype.h"



/**
 * _putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _eputs – displays a string
 * @str: the string to be displayed
 * Return: Nothing will be displayed
 */
void _eputs(char *str)
{
	int initial = 0;

	if (!str)
		return;
	while (str[initial] != '\0')
	{
		_eputchar(str[initial]);
		initial++;
	}
}

/**
 * _eputchar - w
 * @c: character to be displayed
 * Return: Success = 1
 */
int _eputchar(char c)
{
	static int initial;
	int two_input = 2;
	static char buffer[WRITE_BUF_SIZE];
	
	if (c == BUF_FLUSH || initial >= WRITE_BUF_SIZE)
	{
		write(two_input, buffer, initial);
		initial = 0;
	}
	if (c != BUF_FLUSH)	
		buffer[initial++] = c;
	return (1);
}


/**
 * _putsfd – displays inputted string
 * @str: string to be displayed
 * @fd: the file describing
 * Return: characters count needed to put
 */
int _putsfd(char *str, int fd)
{
	int initial = 0;

	if (!str)
		return (initial);
	while (*str)
	{
		initial += _putfd(*str++, fd);
	}
	return (initial);
}



