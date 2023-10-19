#include "main.h"
/**
 * read_line_from_file - read a line from a file
 * @inputFile: input file
 *
 * Return: a line read from the file
 */
char *read_line_from_file(FILE *inputFile)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, inputFile);

	if (read == -1)
	{
		free(line);
		return (NULL);
	}
	if (line[read - 1] == '\n')
	{
		line[read - 1] = '\0';
	}

	return (line);
}
