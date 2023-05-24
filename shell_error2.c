#include "shell_prototype.h"


/**
 * print_error – displays error message
 * @info: parameter and structure to be returned
 * @estr: error type
 * Return: 0 if no number present
 */
void print_error(info_t *info, char *estr)
{
	int success = 0;

	_eputs(info->file_name);
	_eputs(": ");
	print_d(info->line_err_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[success]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d – prints decimal to base 10
 * @input: input from user
 * @fd: file described
 *
 * Return: character count
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int placeholder = 0;
	int initial, num_count = 0;
	unsigned int _absolute_, present;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < placeholder)
	{
		_absolute_ = -input;
		__putchar('-');
		num_count++;
	}
	else
		_absolute_ = input;
	present = _absolute_;
	for (initial = 1000000000; initial > 1; initial /= 10)
	{
		if (_absolute_ / initial)
		{
			__putchar('0' + present / initial);
			num_count++;
		}
		present %= initial;
	}
	__putchar('0' + present);
	num_count++;

	return (num_count);
}

/**
 * _erratoi – changed interger from string
 * @s: string to be changed
 * Return: 0 if no number
 */
int _erratoi(char *s)
{
	int initial = 0;
	int fail = -1;
	unsigned long int answer = 0;

	if (*s == '+')
		s++;
	for (initial = 0;  s[initial] != '\0'; initial++)
	{
		if (s[initial] >= '0' && s[initial] <= '9')
		{
			answer *= 10;
			answer += (s[initial] - '0');
			if (answer > INT_MAX)
				return (fail);
		}
		else
			return (fail);
	}
	return (answer);
}


/**
 * convert_number – changing function
 * @num: number which we evualted
 * @base: base number
 * @flags: argument patterns
 *
 * Return: string to display
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array_check;
	static char buffer[50];
	char signature = 0;
	char *point;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && n > 0)
	{
		n = -num;
		signature = '-';

	}
	array_check
		= flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	point = &buffer[49];
	*point = '\0';

	do	{
		*--point = array_check[n % base];
		n /= base;
	} while (n != 0);

	if (signature)
		*--point = signature;
	return (point);
}

/**
 * remove_comments – replacement of characters
 * @buf: location of the buffer
 *
 * Return: Success = 0;
 */
void remove_comments(char *buf)
{
	int initial = 0;

	for (initial = 0; buf[initial] != '\0'; initial++)
		if (buf[initial] == '#' && (!initial || buf[initial - 1] == ' '))
		{
			buf[initial] = '\0';
			break;
		}
}


