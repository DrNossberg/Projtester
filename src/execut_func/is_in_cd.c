/*
** EPITECH PROJECT, 2018
** projTester
** File description:
** 
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "prototypes.h"

char *is_in_cd(clname_t *cd_tree, char *path, char *function)
{
	clname_t *node = cd_tree;
	char *retour = NULL;

	path = add_slash(path);
	for (; node; node = node->next) {
		if (!node->str)
			continue;
		retour = is_innode(path, node->str, function);
		if (retour)
			break;
		if (node->chld_cl && launch_child(node, path,
			function, &retour))
			break;
	}
	free(path);
	return (retour);
}

char *launch_child(clname_t *node, char *path, char *function,
char **retour)
{
	char *chld_path = NULL;

	path = add_slash(path);
	chld_path = stradd(path, node->str, 0);
	*retour = is_in_cd(node->chld_cl, chld_path, function);
	free(chld_path);
	return (*retour);
}

char *is_innode(char *path, char *filename, char *function)
{
	char *func_path = stradd(path, filename, 0);

	if (!strcmp(filename, function))
		return (func_path);
	free(func_path);
	return (NULL);
}
