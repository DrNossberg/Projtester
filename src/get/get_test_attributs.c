/*
** EPITECH PROJECT, 2018
** projTester
** File description:
** return the arg wrote in the file passed as arg
*/

#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <prototypes.h>

char **get_args_line(char *buffer)
{
	int i = 0;
	int arglen = 2;
	char **arg = NULL;

	arglen += count_argnbr(buffer);
	arg = malloc(sizeof(char *) * (arglen + 1));
	arg[0] = NULL;
	for (i = 1; i < arglen; i++)
		arg[i] = get_next_arg(&buffer);
	arg[arglen] = NULL;
	return (arg);
}

char **get_test_attribut(char *buffer)
{
	char **arg = NULL;
	char *temp = buffer;

	while (*temp && *temp != ':')
		temp++;
	if (*temp)
		temp++;
	arg = get_args_line(temp);
	free(buffer);
	return (arg);
}

int count_argnbr(char *str)
{
	int i = 0;
	int len = 0;

	for (; str[i]; i++)
		if (str[i] == ' ')
			len++;
	return (len);
}

char *get_next_arg(char **str)
{
	int len = 0;
	char *arg = NULL;

	for (len = 0; (*str)[len] && (*str)[len] != ' '
	&& (*str)[len] != '\n'; len++);
	arg = strndup(*str, len);
	*str += len;
	while ((**str) && (**str) == ' ')
		(*str)++;
	if (!arg)
		return (NULL);
	return (arg);
}
