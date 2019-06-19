/*
** EPITECH PROJECT, 2018
** projTester
** File description:
** parse the file
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#include <fcntl.h>
#include "stradd.h"
#include "struct.h"
#include "prototypes.h"

clname_t *read_test(clname_t *node, char *path)
{
	FILE *fd;
	size_t n = 0;
	char *buffer = NULL;

	if (open_file(path, node->str, &fd))
		return (NULL);
	getdelim(&buffer, &n, '\n', fd);
	node->args = get_test_attribut(buffer);
	buffer = NULL;
	getdelim(&buffer, &n, '\0', fd);
	node->res = get_test_res(buffer);
	node->path = get_path(path);
	if (!node->args && !node->res)
		return (NULL);
	free(buffer);
	fclose(fd);
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
