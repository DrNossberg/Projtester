/*
** EPITECH PROJECT, 2018
** projTester
** File description:
** parse the file
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#include <stdio.h>
#include <fcntl.h>
#include <struct.h>
#include <prototypes.h>

clname_t *fill_node_info(clname_t *node, char *path)
{
	FILE *fd;
	size_t n = 0;
	char *buffer = NULL;

	if (check_extension(node->str))
		return (node);
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

int check_extension(char *name)
{
	int len = strlen(name);

	if (len < 4)
		return (84);
	if (!strcmp(name + len - 4, ".tdf"))
		return (0);
	return (1);
}

int open_file(char *way, char *file_name, FILE **fd)
{
	char *file_path = NULL;

	way = add_slash(way);
	file_path = stradd(way, file_name, 1);
	if (!file_path)
		return (84);
	*fd = fopen(file_path, "r");
	if (*fd == NULL)
		return (84);
	free(file_path);
	return (0);
}
