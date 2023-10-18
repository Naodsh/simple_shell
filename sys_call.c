#include "main.h"

/**
 * sys_call - check system call
 * @args: argument
 * @name: program name
 *
 * Return: integer sucess or failure
 */
int sys_call(char **args, char *name)
{
	char path[1024], *all_path = getenv("PATH"), *dir;

	if (access(args[0], X_OK) == 0)
		return (access_cmd(args[0], args));

	strcpy(path, all_path);
	dir = strtok(path, ":");

	while (dir != NULL)
	{
		char full_path[256];

		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, args[0]);

		if (access(full_path, X_OK) == 0)
			return (access_cmd(full_path, args));
		dir = strtok(NULL, ":");
	}
	perror(name);

	return (-1);
}
