/*
** EPITECH PROJECT, 2018
** projTester
** File description:
** browse the path looking for the function
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "struct.h"
#include "prototypes.h"

char *is_in_path(char **env, char *function)
{
	char **arpath = my_path_to_ar(my_getpath(env));
	char *path = NULL;
	int i = 0;

	if (!arpath)
		return (NULL);
	path = find_the_right_path(arpath, function);
	for (; arpath[i + 1]; i++) 
		free(arpath[i]);
	free(arpath);
	return (path);
}

char *my_getpath(char **env)
{
	int i = 0;

	for (; env[i] && strncmp("PATH=", env[i], 5); i++);
	if (!env[i])
		return (NULL);
	return (strdup(env[i] + 5));
}

char *find_the_right_path(char **arpath, char *instruction)
{
	char *path = NULL;

	for (int i = 0; arpath[i]; i++) {
		path = stradd(arpath[i], instruction, 0);
		if (!access(path, X_OK))
			return (path);
		free(path);
	}
	return (NULL);
}

char **my_path_to_ar(char *path)
{
	char **arpath = str_to_word_array(path, ':');

	free(path);
	return (full_with_slash(arpath));
}

char **full_with_slash(char **arpath)
{
	char *temp = NULL;

	for (int i = 0; arpath[i]; i++) {
		temp = arpath[i];
		arpath[i] = add_slash(temp);
		free(temp);
	}
	return (arpath);
}
