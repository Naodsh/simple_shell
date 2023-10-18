#include "main.h"

/**
 * parser_strings - tokinezes strings into an array of string
 * @line: strings
 *
 * Return: array of string
 */
char **parser_strings(char *line)
{
	int buffer = MAX_ARGS;
	int index = 0;
	char *token;
	char **tokens;

	tokens = malloc(buffer * sizeof(char *));
	if (!tokens)
	{
		perror("memory allocation");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOKEN_DELIM);
	while (token != NULL)
	{
		tokens[index] = token;
		index++;
		if (index >= buffer)
		{
			buffer += buffer;
			tokens = realloc(tokens, buffer * sizeof(char *));
			if (tokens == NULL)
			{
				perror("reallocation error");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOKEN_DELIM);
	}
	tokens[index] = NULL;
	return (tokens);
}
