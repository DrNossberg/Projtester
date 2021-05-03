/*
** EPITECH PROJECT, 2019
** projTester
** File description:
** locate the exec passed as argument and return the absolute path to it
*/

#include <stdlib.h>

#include "prototypes.h"

char *locate_exec(clname_t *test_tree, argd_t *arg_data, char **env)
{
    printf("exec : %s\n", arg_data->exec);
    char *exec_path = search_in_current_directory(test_tree, "./", arg_data->exec);

    if (!exec_path)
        exec_path = search_in_path(env, arg_data->exec);
    if (!exec_path) {
        fprintf(stderr, "Executable passed as argument hasn't been found : %s\n", arg_data->exec);
        exit(84);
    }
    return (exec_path);
}
