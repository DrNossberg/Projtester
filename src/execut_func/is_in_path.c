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
	char **arpath = NULL;
	char *path = NULL;

	arpath = my_path_to_ar(my_getpath(env));
	if (!arpath)
		return (NULL);
	path = find_the_right_path(arpath, function);
	for (int i = 0; arpath[i + 1]; i++)
		free(arpath[i]);
	free(arpath);
	return (path);
}

char *my_getpath(char **env)
{
	char *path = NULL;
	int i = 0;
	int lenpath = 0;

	for (; env[i] && strncmp("PATH=", env[i], 5); i++);
	if (!env[i])
		return (NULL);
	lenpath = strlen(env[i] + 5);
	path = malloc(sizeof(char) * (lenpath + 1));
	strcpy(path, env[i] + 5);
	path[lenpath] = '\0';
	return (path);
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
		if (temp)
			free(temp);
		temp = NULL;
	}
	return (arpath);
}
