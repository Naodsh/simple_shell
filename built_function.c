#include "main.h"
/**
 * cd_f - changes the working directory and updates PWD
 * @args: directory
 *
 * Return: 0 on success, -1 on failure
 */
int cd_f(char **args)
{
	char *new_dir, *current_dir;

	if (args[1] == NULL || strcmp(args[1], "~") == 0)
	{
		new_dir = getenv("HOME");
	}
	else if (strcmp(args[1], "-") == 0)
	{
		new_dir = getenv("OLDPWD");
	}
	else
	{
		new_dir = args[1];
	}
	current_dir = getcwd(NULL, 0);
	if (new_dir == NULL || current_dir == NULL)
	{
		perror("getcwd or getenv");
		return (-1);
	}
	if (setenv("OLDPWD", current_dir, 1) != 0)
	{
		perror("setenv OLDPWD");
		return (-1);
	}
	if (chdir(new_dir) != 0)
	{
		perror("error: changing directory");
		return (-1);
	}
	free(current_dir);

	return (0);
}

/**
 * exit_f - exit
 * @args: arguments
 *
 * Return: an interger
 */
int exit_f(char **args)
{
	if (args[1])
	{
		return (atoi(args[1]));
	}
	else
	{
		return (0);
	}
}

/**
 * env_f - env function
 * @args: argument
 *
 * Return: an integer
 */
int env_f(char **args)
{
	int i = 0;

	args = environ;
	while (args[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}

	return (-1);
}
