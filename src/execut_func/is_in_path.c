/*
** EPITECH PROJECT, 2018
** projTester
** File description:
** browse the path looking for the function
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "stradd.h"
#include "struct.h"
#include "prototypes.h"

char *is_in_path(char **env, char *function)
{
	char **arpath = my_path_to_ar(my_getpath(env));
	char *path = NULL;

	if (!arpath)
		return (NULL);
	path = find_the_right_path(arpath, function);
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
		path = strfadd(arpath[i], instruction, FREE_STRA);
		if (!access(path, X_OK)) {
			for (; arpath[++i]; free(arpath[i]));
			return (path);
		}
		free(path);
	}
	return (NULL);
}

char **my_path_to_ar(char *my_get_path)
{
	char **arpath = str_to_word_array(my_get_path, ':');
	char *temp = NULL;

	free(my_get_path);
	for (int i = 0; arpath[i]; i++) {
		temp = arpath[i];
		arpath[i] = add_slash(temp);
		free(temp);
	}
	return (arpath);
}
