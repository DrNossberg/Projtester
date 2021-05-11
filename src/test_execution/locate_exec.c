/*
** EPITECH PROJECT, 2019
** projTester
** File description:
** locate the exec passed as argument and return the absolute path to it
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "prototypes.h"

char *locate_exec(argd_t *arg_data, char **env) {
    char *exec_path = search_in_current_directory(arg_data->exec);

    if (!exec_path)
        exec_path = search_in_path(env, arg_data->exec);
    if (!exec_path) {
        fprintf(stderr, "Executable hasn't been found : %s\n", arg_data->exec);
        exit(84);
    }
    return (exec_path);
}

char *search_in_current_directory(char *exec) {
    if (!access(exec, X_OK))
        return (strdup(exec));
    return (NULL);
}
