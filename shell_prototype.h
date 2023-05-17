#ifndef _SHELL_PROTOTYPE_H_
#define _SHELL_PROTOTYPE_H_
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* reads to buffer ands writes to buffer */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3


/* for changing to uppercase and lowercase */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;

/**
 * struct liststr – single linked list for the function checking
 * @number: number field
 * @string_check: a string datatype
 * @next: tansveres to the next node in line
 */
typedef struct liststr
{
	int number;
	char *string_check;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - Struct for holding information
 * @arg: string formed after arguements
 * @argv:multiple strings formed after parameters inputted
 * @path: a string path for the current command
 * @alias: the alias node
 * @env_change: checks if the environment has been changed
 * @status:gives back the last command ran
 * @cmd_buffer: pointer location/address
 * @cmd_buffer_type: Cmd commands
 * @argc: counts the number of parameters/arguements
 * @line_err_count: counts number of errors
 * @err_num: error try catch code
 * @linecount_pattern: count of the lines
 * @file_name: the name of the program
 * @env: a duplicate of linked list environment
 * @environ: environment modifier
 * @history_node: the history node
 * @readfd: the fd that will be red
 * @history_count: past number counts
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_err_count;
	int err_num;
	int linecount_pattern;
	char *file_name;
	list_t *env;
	list_t *history_node;
	list_t *alias;
	char **environ;
	int env_change;
	int status;
	char **cmd_buffer;
	int cmd_buffer_type;
	int readfd;
	int history_count;
} info_t;

#define INFO_INIT
/**
 * struct builtin - has a builtin function which are related
 * @kind: the builtin command pattern
 * @func: the function to be executed
 */
typedef struct builtin
{
	char *kind;
	int (*func)(info_t *);
} builtin_table;

int loophsh(char **);

void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);


int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);





char **strtow(char *, char *);
char **strtow2(char *, char);


int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);


int bfree(void **);

char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);


char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);


int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);


int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

int _myhistory(info_t *);
int _myalias(info_t *);

ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);


list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);


int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);


char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);


#endif


