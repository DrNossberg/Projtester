/*
** EPITECH PROJECT, 2018
** projTester
** File description:
** parse the file
*/

#include <stdlib.h>
#include "stradd.h"
#include "struct.h"
#include "prototypes.h"

clname_t *read_test(clname_t *node, char *path)
{
	FILE *fd;

	if (open_file(path, node->str, &fd))
		return (NULL);
	node->path = get_path(path);
	node->args = get_test_attribut(fd);
	node->res  = get_test_res(fd);
	fclose(fd);
	if (!node->path || !node->args || !node->res)
		return (NULL);
	return (node);
}

int open_file(char *path, char *file_name, FILE **fd)
{
	char *file_path = NULL;

	file_path = strfadd(add_slash(path), file_name, FREE_STRA);
	if (!file_path)
		return (84);
	*fd = fopen(file_path, "r");
	if (*fd == NULL) {
		perror("fopen");
		free(file_path);
		exit (84);
	}
	free(file_path);
	return (0);
}
