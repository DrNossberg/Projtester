/*
** EPITECH PROJECT, 2018
** projTester
** File description:
** modify and return the path
*/

#include <stdlib.h>
#include <unistd.h>
#include "struct.h"
#include "prototypes.h"


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
		path = stradd(arpath[i], instruction);
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
	for (int i = 0; arpath[i]; i++)
		arpath[i] = add_slash(arpath[i]);
	return (arpath);
}
