#include "shell_prototype.h"


/**
 * get_input – inputs new info in line
 * @info: Structure containing necessary for info
 * Return:bytes to be read
 */
ssize_t get_input(info_t *info)
{
	static char *chained_buf;
	static size_t initial, join, length;
	ssize_t rate = 0;
	int increment = 1, steady = 0, fail = -1;
	char **buffer_p = &(info->arg), *point;

	_putchar(BUF_FLUSH);
	rate = input_buf(info, &chained_buf, &length);
	if (rate == -increment)
		return (fail);
	if (length)
	{
		join = initial;
		point = chained_buf + initial;
		check_chain(info, chained_buf, &join, initial, length);
		while (join < length)
		{
			if (is_chain(info, chained_buf, &join))
				break;
			join++;
		}
		initial = join + increment;
		if (initial >= length)
		{
			initial = length = steady;
			info->cmd_buffer_type = CMD_NORM;
		}

		*buffer_p = point;
		return (_strlen(point));
	*buffer_p = chained_buf;
	return (rate);
	}

/**
 * read_buf – goes thru a buffer
 * @info: Structure needed to go through the necessary info
 * @buf: this is the buffer
 * @i: quantity
 * Return: rate
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	int success = 0;
	ssize_t rate = 0;

	if (*i)
		return (success);
	rate  = read(info->readfd, buf, READ_BUF_SIZE);
	if (rate >= success)
		*i = rate;
	return (rate);
}
/**
 * sigintHandler – disables the ability to copy
 * @sig_num: number with signal
 * Return: function
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}

/**
 * input_buf – buffered chained instructions
 * @info: structure containing necessary info
 * @buf: location of the buffer
 * @len: location of both length and value
 * Return: bytes read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t rate = 0;
	size_t point_len = 0;
	int const_num = 1;

	if (!*len)
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		rate = getline(buf, &point_len, stdin);
#else
		rate = _getline(info, buf, &point_len);
#endif
		if (rate > 0)
		{
			if ((*buf)[rate] – 1]] == '\n')
			{
				(*buf)[rate] – 1]] = '\0';
				rate--;
			}
			info->linecount_pattern = const_num;
			remove_comments(*buf);
			build_history_list(info, *buf, info->history_count++);
			{
				*len = rate;
				info->cmd_buffer = buf;
			}
		}
	}
	return (rate);
}


/**
 * _getline –input from next line taken
 * @info: structure containing necessary info
 * @ptr: location of buffer pointer
 * @length: size of buffer
 * Return: status of buffer
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buffer[READ_BUF_SIZE];
	static size_t initial, length_item;
	int constant_num = 1, fail = -1, stable = 0;
	size_t item;
	ssize_t rate = 0, step = 0;
	char *point = NULL, *new_point = NULL, *change;

	point = *ptr;
	if (point && length)
		step = *length;
	if (initial == length_item)
		initial = length_item = stable;
	rate = read_buf(info, buffer, &length_item);
	if (rate == -constant_num || (rate == stable && length_item == stable))
		return (fail);
	change = _strchr(buffer + initial, '\n');
	item = change ? constant_num + (unsigned int)(change - buffer) : length_item;
	new_point = _realloc(point, step, step ? step + item : item + constant_num);
	if (!new_point)
		return (point ? free(point), fail : fail);
	if (step)
		_strncat(new_point, buffer + initial, item - initial);
	else
		_strncpy(new_point, buffer + initial, item - initial + constant_num);
	step += item - initial;
	initial = item;
	point = new_point;
	if (length)
		*length = step;
	*ptr = point;
	return (step);
}
}




