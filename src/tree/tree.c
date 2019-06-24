/*
** EPITECH PROJECT, 2018
** projTester
** File description:
** reproduce the tree function
*/

#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fnmatch.h>
#include "stradd.h"
#include "struct.h"
#include "prototypes.h"

clname_t *build_tree(char **argv)
{
	clname_t *cl_name = NULL;

    if (argv[2])
       cl_name = tree(argv[1], argv[2]);
    else
       cl_name = tree(argv[1], NULL);
	if (!cl_name)
		return (NULL);
	return (cl_name);
}

clname_t *tree(char *path, char *function)
{
    struct dirent **namelist;
	clname_t *node = init_cl();
	int n = scandir(path, &namelist, my_filter_function, alphasort);

    if (n == -1) {
       perror("scandir");
       return (NULL);
    }
	while (n--) {
		if (strstr(namelist[n]->d_name, ".tdf")) {
			node = create_test_node(node, function, namelist[n]->d_name, path);
		} else
			node = do_recursive(node, namelist[n], function, path);
		free(namelist[n]);
	}
	free(namelist);
	return (node);
}

clname_t *do_recursive(clname_t *node, struct dirent *file,
    char *function, char *path)
{
	char *child_path = strfadd(add_slash(path), file->d_name, FREE_STRA);

	node = add_clname_node(node, file->d_name);
	node->chld_cl = tree(child_path, function);
	free(child_path);
	return (node);
}

int my_filter_function(const struct dirent *item)
{
    char my_pattern[] = "*.tdf";
    struct stat stbuf;

    if (item->d_name[0] == '.')
        return (0);
#ifdef _DIRENT_HAVE_D_TYPE
    if (item->d_type != DT_UNKNOWN && item->d_type != DT_LNK) {
        if (item->d_type == DT_DIR)
            return (1);
    } else
#endif
    {
        stat(item->d_name, &stbuf);
        if (S_ISDIR(stbuf.st_mode))
            return (1);
    }
   return (fnmatch(my_pattern, item->d_name, FNM_PERIOD) == 0);
}
