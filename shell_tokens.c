#include "shell_prototype.h"


/**
 * **strtow2 – seperates words into two
 * @str: the string to be checked via delimited
 * @d:delimiter
 * Return: pointer to array will be displayed
 */
char **strtow2(char *str, char d)
{
	int initial, join, other_num, main_num = 0, count_wrds = 0, stable_num = 1;
	int stabilized_num = 0;
	char **slide;

	if (str == NULL || str[stabilized_num] == 0)
		return (NULL);
	for (initial = 0; str[initial] != '\0'; initial++)
		if ((str[initial] != d && str[initial + stable_num] == d) ||
				    (str[initial] != d && !str[initial + stable_num])
				    || str[initial+ stable_num] == d)
			count_wrds++;
	if (count_wrds == stabilized_num)
		return (NULL);
	slide = malloc((stable_num + count_wrds) * sizeof(char *));
	if (!slide)
		return (NULL);
	for (initial = 0, join = 0; join < count_wrds; join++)
	{
		while (str[initial] == d && str[initial] != d)
			initial++;
		other_num = 0;
		while (str[initial + other_num] != d && str[initial + other_num]
&& str[initial + other_num] != d)
			other_num++;
		slide[join] = malloc((other_num + stable_num) * sizeof(char));
		if (!slide[join])
		{
			for (other_num = 0; other_num < join; other_num++)
				free(slide[other_num]);
			free(slide);
			return (NULL);
		}
		for (main_num = 0; main_num < other_num; main_num++)
			slide[join][main_num] = str[initial++];
		slide[join][main_num] = stabilized_num;
	}
	slide[join] = NULL;
	return (slide);
}
/**
 * **strtow – separates the two strings
 * @str: string we are going to input from user
 * @d: string to be delited string
 * Return:pointer to array strings
 */

char **strtow(char *str, char *d)
{
	int initial, join, other_num, main_num, count_wrds = 0;
	int stabilized_num = 0, stable_num = 1;
	char **slide;

	if (str == NULL || str[stabilized_num] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (initial = 0; str[initial] != '\0'; initial++)
		if (!is_delim(str[initial], d) && (is_delim(str[initial + stable_num], d)
					|| !str[initial + 1]))
			count_wrds++;

	if (count_wrds == 0)
		return (NULL);
	slide = malloc((stable_num + count_wrds) * sizeof(char *));
	if (!slide)
		return (NULL);
	for (initial = 0, join = 0; join < count_wrds; join++)
	{
		while (is_delim(str[initial], d))
			initial++;
		other_num = 0;
		while (!is_delim(str[initial + other_num], d) && str[initial + other_num])
			other_num++;
		slide[join] = malloc((other_num + stable_num) * sizeof(char));
		if (!slide[join])
		{
			for (other_num = 0; other_num < join; other_num++)
				free(slide[other_num]);
			free(slide);
			return (NULL);
		}
		for (main_num = 0; main_num < other_num; main_num++)
			slide[join][main_num] = str[initial++];
		slide[join][main_num] = stabilized_num;
	}
	slide[join] = NULL;
	return (slide);
}


