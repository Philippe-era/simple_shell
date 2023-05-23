#include "shell_prototype.h"

/**
 * dup_chars – copies characters
 * @pathstr: the destination of string
 * @start: start number
 * @stop_index: ending number
 *
 * Return: pointer to new buffer
 */
char *dup_chars(char *pathstr, int start, int stop_index)
{
	static char buffer[1024];
	int initial = 0, other_num = 0;

	for (other_num = 0, initial = start; initial < stop_index; initial++)
		if (pathstr[initial] != ':')
			buffer[other_num++] = pathstr[initial];
	buffer[other_num] = 0;
	return (buffer);
}

/**
 * is_cmd – checks if file is executable
 * @info: Structure containing necessary files
 * @path: location to file
 *
 * Return: 1 if success
 */
int is_cmd(info_t *info, char *path)
{
	struct stat steady;
	int success = 1, fail = 0;

	(void)info;
	if (!path || stat(path, &steady))
		return (fail);

	if (steady.st_mode & S_IFREG)
	{
		return (success);
	}
	return (fail);
}

/**
 * find_path - finds this cmd in the PATH string
 * @info: Structure containing necessary info for structure
 * @pathstr: the PATH string
 * @cmd: the cmd to be checked for
 *
 * Return: the checked cmd
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int initial = 0, current_position = 0, starting_index = 1;
	char *location;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (starting_index)
	{
		if (!pathstr[initial] || pathstr[initial] == ':')
		{
			location = dup_chars(pathstr, current_position, initial);
			if (!*location)
				_strcat(location, cmd);
			else
			{
				_strcat(location, "/");
				_strcat(location, cmd);
			}
			if (is_cmd(info, location))
				return (location);
			if (!pathstr[initial])
				break;
			current_position = initial;
		}
		initial++;
	}
	return (NULL);
}


