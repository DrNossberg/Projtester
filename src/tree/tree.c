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
#include "colors.h"

clname_t *build_tree(char *path, argd_t *arg_data) {
    struct dirent **namelist;
    clname_t *node = init_cl();
    int n = my_scandir(path, &namelist);
    char *child_path = NULL;

    while (n--) {
        if (!fnmatch(TESTFILE_PATTERN, namelist[n]->d_name, 0))
            node = create_test_node(node, arg_data->exec, namelist[n]->d_name, path);
        else {
            child_path = strfadd(add_slash(path), namelist[n]->d_name, FREE_STRA);
            node = add_clname_node(node, namelist[n]->d_name);
            node->chld_cl = build_tree(child_path, arg_data);
            free(child_path);
        }
        free(namelist[n]);
    }
    free(namelist);
    return (node);
}

int my_scandir(char *path, struct dirent ***namelist) {
    int n = scandir(path, namelist, my_filter_function, alphasort);

    if (n == -1) {
        fprintf(stderr, "Error while tying to scan the gived dir : %s\n",
            strerror(errno));
        exit(84);
    }
    return (n);
}

int my_filter_function(const struct dirent *item) {
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
   return (fnmatch(TESTFILE_PATTERN, item->d_name, FNM_PERIOD) == 0);
}
