#include "main.h"

/**
 * shell_non_interactive - shell_non_interactive
 * @name: program name
 *
 * Return: void
 */
void shell_non_interactive(char *name, char *input_file)
{
	char *line;
	char **args;
	int status;

	FILE *file = fopen(input_file, "r");

	if  (file == NULL)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}

	while ((line = read_line_from_file(file)) != NULL)
	{
		args = parser_strings(line);
		status = execute_cmd(args, name);
		free(line);
		free(args);

		if (status >= 0)
		{
			exit(status);
		}
	}
	fclose(file);
}
