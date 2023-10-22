#include "main.h"

/**
 * shell_interactive  - interactive mode
 * @name: program name
 *
 * Return: void
 */
void shell_interactive(char *name)
{
	char *line;
	char **args;
	int status;

	while (1)
	{
		write(0, "$ ", 2);
		signal(SIGINT, handle_ctrlc);
		line = read_input();
		args = parser_strings(line);
		status = execute_cmd(args, name);
		free(line);
		free(args);

		if (status >= 0)
			exit(status);
		else
			continue;
	}
}
