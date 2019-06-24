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
#include "stradd.h"
#include "struct.h"
#include "prototypes.h"

char *is_in_cd(clname_t *cd_tree, char *path, char *function)
{
	clname_t *node = cd_tree;
	char *retour = NULL;
	char *tmp = add_slash(path);

	for (; node; node = node->next) {
		if (!node->test_name)
			continue;
		retour = is_innode(tmp, node->test_name, function);
		if (retour)
			break;
		if (node->chld_cl && launch_child(node, tmp,
			function, &retour))
			break;
	}
	free(tmp);
	return (retour);
}

char *launch_child(clname_t *node, char *path, char *function,
char **retour)
{
	char *tmp = add_slash(path);
	char *chld_path = stradd(tmp, node->test_name);

	*retour = is_in_cd(node->chld_cl, chld_path, function);
	free(chld_path);
	free(tmp);
	return (*retour);
}

char *is_innode(char *path, char *filename, char *function)
{
	char *func_path = stradd(path, filename);

	if (!strcmp(filename, function))
		return (func_path);
	free(func_path);
	return (NULL);
}
