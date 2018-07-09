/*
** EPITECH PROJECT, 2018
** projTester
** File description:
** reproduce the tree function
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <struct.h>
#include <prototypes.h>

clname_t *tree(char *path, int basepathlen)
{
	DIR *rep = opendir(path);
	struct dirent *file = NULL;
	clname_t *node = NULL;

	if (open_n_init(&rep, &file, &node))
		return (NULL);
	while (file) {
		if (file->d_type == DT_REG) {
			node = add_clname_node(node, file->d_name, basepathlen);
			node = fill_node_info(node, path);
		}
		if (file->d_type == DT_DIR && strcmp(file->d_name, ".")
			&& strcmp(file->d_name, ".."))
			node = do_recursive(node, file, path, basepathlen);
		file = readdir(rep);
	}
	closedir(rep);
	return (node);
}

int open_n_init(DIR **rep, struct dirent **file,
clname_t **node)
{
	if (!*rep)
		return (84);
	*file = readdir(*rep);
	*node = init_cl();
	if (!*node)
		return (84);
	return (0);
}

clname_t *do_recursive(clname_t *node, struct dirent *file,
char *path, int basepathlen)
{
	char *child_path = NULL;

	child_path = stradd(stradd(path, "/", 0), file->d_name, 1);
	node = add_clname_node(node, file->d_name, basepathlen);
	node->chld_cl = tree(child_path, basepathlen);
	free(child_path);
	return (node);
}

clname_t *sort_tree(clname_t *p_head)
{
	clname_t *node = p_head;

	while (is_arranged(node))
		node = bubble_sort(node);
	return (node);
}
