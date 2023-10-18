#include "main.h"

/**
 * shell_non_interactive - shell_non_interactive
 * @name: program name
 *
 * Return: void
 */
void shell_non_interactive(char *name)
{
	char *line;
	char **args;
	int status;
	ssize_t read;
	size_t len = 0;

	while ((read = getline(&line, &len, stdin)) != -1)
	{
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		args = parser_strings(line);
		status = execute_cmd(args, name);
		free(args);

		if (status >= 0)
		{
			free(line);
			exit(status);
		}
	}
}
