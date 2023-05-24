#include "shell_prototype.h"

/**
 * input_buf – chained buffer commands
 * @info: Struct containing parameters necessary
 * @buf: location of buffer
 * @len: lens of address
 * Return: bytes to be read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t read_line = 0;
	size_t len_pointer = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		read_line = getline(buf, &len_pointer, stdin);
#else
		read_line = _getline(info, buf, &len_pointer);
#endif
		if (read_line > 0)
		{
			if ((*buf)[read_line - 1] == '\n')
			{
				(*buf)[read_line - 1] = '\0';
				read_line--;
			}
			info->linecount_pattern = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->history_count++);
			{
				*len = read_line;
				info->cmd_buffer = buf;
			}
		}
	}
	return (read_line);
}

/**
 * get_input – deletes one line from parameter
 * @info: Structure containing necessary parameters
 *
 * Return: read_lines bytes
 */
ssize_t get_input(info_t *info)
{
	static char *buffer;
	static size_t initial, join, length;
	ssize_t read_line = 0;
	char **buffer_point = &(info->arg), *point;
	int fail = -1;

	_putchar(BUF_FLUSH);
	read_line = input_buf(info, &buffer, &length);
	if (read_line == -1)
		return (fail);
	if (length)
	{
		join = initial;
		point = buffer + initial;

		check_chain(info, buffer, &join, initial, length);
		while (join < length)
		{
			if (is_chain(info, buffer, &join))
				break;
			join++;
		}
		initial = join + 1;
		if (initial >= length)
		{
			initial = length = 0;
			info->cmd_buffer_type = CMD_NORM;
		}
		*buffer_point = point;
		return (_strlen(point));
	}
	*buffer_point = buffer;
	return (read_line);
}

/**
 * read_buf – buffer to be read through
 * @info: Structure containing necessary info
 * @buf: buffer to be examined
 * @i: length
 * Return: read
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t read_line = 0;
	int success = 0;

	if (*i)
		return (success);
	read_line = read(info->readfd, buf, READ_BUF_SIZE);
	if (read_line >= 0)
		*i = read_line;
	return (read_line);
}

/**
 * _getline – information from the next line will be got
 * @info: Structure containing necessary files
 * @ptr: location of pointer
 * @length: memory allocation for buffer
 *
 * Return: status
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buffer[READ_BUF_SIZE];
	static size_t initial, length_check;
	size_t other_num;
	ssize_t read_line = 0, status = 0;
	char *point = NULL, *new_point = NULL, *control;
	int fail = -1, success = 1;

	point = *ptr;
	if (point && length)
		status = *length;
	if (initial == length_check)
		initial = length_check = 0;

	read_line = read_buf(info, buffer, &length_check);
	if (read_line == -1 || (read_line == 0 && length_check == 0))
		return (fail);

	control = _strchr(buffer + initial, '\n');
	other_num = control ? success + (unsigned int)(control - buffer) : length_check;
	new_point =
		_realloc(point, status, status ? status + other_num : other_num + success);
	if (!new_point)
		return (point ? free(point), fail : fail);

	if (status)
		_strncat(new_point, buffer + initial, other_num - initial);
	else
		_strncpy(new_point, buffer + initial, other_num - initial + success);

	status += other_num - initial;
	initial = other_num;
	point = new_point;

	if (length)
		*length = status;
	*ptr = point;
	return (status);
}

/**
 * sigintHandler – doesn’t allow the shortcut ctrl - c
 * @sig_num: number signal to be transmitted
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}



