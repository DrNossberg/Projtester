/*
** EPITECH PROJECT, 2018
** projTester
** File description:
** parse the file
*/

#include <string.h>
#include <stdlib.h>

#include "stradd.h"
#include "struct.h"
#include "prototypes.h"

clname_t *create_test_node(clname_t *p_head, char *function, char *test_name, char *path) {
    clname_t *node = add_clname_node(p_head, test_name);
    FILE *fd;

    if (!function && node)
        return (node);
    if (!node || open_file(path, node->test_name, &fd))
        return (NULL);
    node->path = get_path(path, &node->pathlen);
    node->args = get_test_attribut(fd);
    node->res  = get_test_res(fd);
    fclose(fd);
    if (!node->path || !node->args)
        return (NULL);
    node->args[0] = strdup(function);
    return (node);
}

int open_file(char *path, char *file_name, FILE **fd) {
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
