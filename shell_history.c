#include "shell_prototype.h"

/**
 * get_history_file - gets the history file
 * @info: structure containing necessary parameter
 *
 * Return: string containing the necessary info
 */

char *get_history_file(info_t *info)
{
	char *buffer, *directory;

	directory = _getenv(info, "HOME=");
	if (!directory)
		return (NULL);
	buffer = malloc(sizeof(char) * (_strlen(directory) + _strlen(HIST_FILE) + 2));
	if (!buffer)
		return (NULL);
	buffer[0] = 0;
	_strcpy(buffer, directory);
	_strcat(buffer, "/");
	_strcat(buffer, HIST_FILE);
	return (buffer);
}

/**
 * write_history – new file created or concatenated
 * @info: structure containing necessary info
 *
 * Return: 1 success , -1 fail
 */
int write_history(info_t *info)
{
	ssize_t file_description;
	char *file_name = get_history_file(info);
	list_t *node_check = NULL;

	if (!file_name)
		return (-1);

	file_description = open(file_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(file_name);
	if (file_description == -1)
		return (-1);
	for (node_check = info->history_node; node_check; node_check = node_check->next)
	{
		_putsfd(node_check->string_check, file_description);
		_putfd('\n', file_description);
	}
	_putfd(BUF_FLUSH, file_description);
	close(file_description);
	return (1);
}

/**
 * read_history – history from file to be read
 * @info: structure containing necessary info
 *
 * Return: history_count on success, 0 otherwise
 */
int read_history(info_t *info)
{
	int initial, last_number = 0, linecount = 0;
	ssize_t file_description, read_line, file_size = 0;
	struct stat st;
	char *buffer = NULL, *file_name = get_history_file(info);

	if (!file_name)
		return (0);

	file_description = open(file_name, O_RDONLY);
	free(file_name);
	if (file_description == -1)
		return (0);
	if (!fstat(file_description, &st))
		file_size = st.st_size;
	if (file_size < 2)
		return (0);
	buffer = malloc(sizeof(char) * (file_size + 1));
	if (!buffer)
		return (0);
	read_line = read(file_description, buffer, file_size);
	buffer[file_size] = 0;
	if (read_line <= 0)
		return (free(buffer), 0);
	close(file_description);
	for (initial = 0; initial < file_size; initial++)
		if (buffer[initial] == '\n')
		{
			buffer[initial] = 0;
			build_history_list(info, buffer + last_number, linecount++);
			last_number = initial + 1;
		}
	if (last_number != initial)
		build_history_list(info, buffer + last_number, linecount++);
	free(buffer);
	info->history_count = last_number;
	while (info->history_count-- >= HIST_MAX)
		delete_node_at_index(&(info->history_node), 0);
	renumber_history(info);
	return (info->history_count);
}

/**
 * build_history_list – inserts new entry into the linked list
 * @info: Structure containing necessary info
 * @buf: buffer to be checked
 * @linecount: the history linecount, history_count
 *
 * Return: Always 0
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *node_check = NULL;

	if (info->history_node)
		node_check = info->history_node;
	add_node_end(&node_check, buf, linecount);

	if (!info->history_node)
		info->history_node = node_check;
	return (0);
}

/**
 * renumber_history – re numbers the last node
 * @info: Structure containing necessary info
 *
 * Return: the new history_count
 */
int renumber_history(info_t *info)
{
	list_t *node_check = info->history_node;
	int initial = 0;

	while (node_check)
	{
		node_check->number = initial++;
		node_check = node_check->next;
	}
	return (info->history_count = initial);
}


