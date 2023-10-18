#ifndef MAIN_H_
#define MAIN_H_


#define MAX_ARGS 64
#define BUFF 1024
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define TOKEN_DELIM " \n\t\r\a\""
extern char **environ;

/**
 * struct built_in - Structure for built-in commands
 * @name: The name of the built-in command
 * @func: A function pointer to the associated command's handler
 *
 * Description:
 * This structure defines the format for built-in commands used in the shell.
 * It associates the name of the command with the function that handles it.
 */
typedef struct built_in
{
	char *name;
	int (*func)(char **);
} built_in;


void shell_interactive(char *name);
void shell_non_interactive(char *name);
char *read_input(void);
char **parser_strings(char *command);
int cd_f(char **args);
int env_f(char **args);
int exit_f(char **args);
int execute_cmd(char **argv, char *name);
int sys_call(char **args, char *name);
int access_cmd(char *full_path, char **args);

#endif


