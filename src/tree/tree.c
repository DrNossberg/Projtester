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
#include <errno.h>

#include "stradd.h"
#include "struct.h"
#include "prototypes.h"

clname_t *build_tree(char **argv)
{
    clname_t *cl_name = NULL;
    int test_dir_len = count_path_folder(argv[1]);

    if (argv[2])
       cl_name = tree(argv[1], argv[2], test_dir_len);
    else
       cl_name = tree(argv[1], NULL, test_dir_len);
    if (!cl_name)
        return (NULL);
    return (cl_name);
}

clname_t *tree(char *path, char *function, int test_dir_len)
{
    struct dirent **namelist;
    clname_t *node = init_cl();
    int n = my_scandir(path, &namelist);
    char *child_path = NULL;

    while (n--) {
        if (strstr(namelist[n]->d_name, ".tdf"))
            node = create_test_node(node, function, namelist[n]->d_name, path);
        else {
            child_path = strfadd(add_slash(path), namelist[n]->d_name, FREE_STRA);
            node = add_clname_node(node, namelist[n]->d_name);
            node->chld_cl = tree(child_path, function, test_dir_len);
            free(child_path);
        }
        if (node)
            node->arg_pathlen = test_dir_len;
        free(namelist[n]);
    }
    free(namelist);
    return (node);
}

int my_scandir(char *path, struct dirent ***namelist)
{
    int n = scandir(path, namelist, my_filter_function, alphasort);

    if (n == -1) {
        fprintf(stderr, "Error while tying to scan the gived dir : %s\n",
            strerror(errno));
        exit(84);
    }
    return (n);
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
