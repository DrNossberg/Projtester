/*
** EPITECH PROJECT, 2018
** projTester
** File description:
** return the array of the path of the current node
*/

#include <string.h>
#include <stdlib.h>
#include "prototypes.h"

char **get_path(char *path)
{
	int i = 0;
	int j = 0;
	int arlen = count_path_node(path);
	char **array = malloc(sizeof(char *) * (arlen + 1));

	array[arlen] = NULL;
	for (int k = 0; k < arlen; k++) {
		while (path[i] && path[i] != '/')
			i++;
		i++;
		for (j = 0; path[i + j] && path[i + j] != '/'; j++);
		array[k] = strndup(path + i, j);
	}
	return (array);
}

int count_path_node(char *path)
{
	int len = 0;

	for (int i = 0; path[i]; i++)
		if (path[i] == '/')
			len++;
	return (len);
}
