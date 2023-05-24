#include "shell_prototype.h"

/**
 * main - where we enter
 * @accurate: argument being counted
 * @accurate_vec: argument vector to be checked
 *
 * Return: 0 successful
 */
int main(int accurate, char **accurate_vec)
{
	info_t info[] = { { 0 } };
	int file_description = 2, fail = -1, exit_cmd = 126, enter_cmd = 127;
	int success = 1;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (file_description)
			: "r" (file_description));

	if (accurate == 2)
	{
		file_description = open(accurate_vec[success], O_RDONLY);
		if (file_description == fail)
		{
			if (errno == EACCES)
				exit(exit_cmd);
			if (errno == ENOENT)
			{
				_eputs(accurate_vec[0]);
				_eputs(": 0: Can't open ");
				_eputs(accurate_vec[success]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(enter_cmd);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = file_description;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, accurate_vec);
	return (EXIT_SUCCESS);
}

