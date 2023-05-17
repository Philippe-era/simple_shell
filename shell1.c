#include "shell_prototype.h"


/**
 * is_delim – function that checks if the character is delimited
 * @c: char chacter ti be analyzed
 * @delim: the string delimited
 * Return: 1 if success, otherwise 
 */
int is_delim(char c, char *delim)
{
	int success = 0;
	int fail = 1;
	while (*delim)
		if (*delim++ == c)
			return (fail);
	return (success);
}
/**
 * interactive – returns shell into interactive mode
 * @info: structures address
 *
 * Return: if successful return success 
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}


/**
 * _isalpha – alphabetic character to be checked
 * @c: character to be inputted
 * Return: return success if c is alphabetic 
 */

int _isalpha(int c)
{
	int success = 1;
	int fail = 0;
/** checks if C is alphabetic */
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (success);
	else
		return (fail);
}

/**
 * _atoi – changes string to integer
 * @s: the string to be changed
 * Return: 0 if there are no characters to be changed , otherwise change the numbers
 */

int _atoi(char *s)
{
	int initial, signature = 1, pattern = 0, display; fail = -1;
	unsigned int answer = 0;

	for (initial = 0; s[initial] != '\0' && pattern != 2; initial++)
	{
		if (s[initial] == '-')
			signature *= -1;

		if (s[initial] >= '0' && s[initial] <= '9')
		{
			int start = 1;
			int finish = 10;
			pattern = start;

			answer *= finish;
			answer += (s[initial] - '0');
		}
		else if (pattern == 1)
			pattern = 2;
	}

	if (signature == fail)
		display = -answer;
	else
		display = answer;

	return (display);
}

