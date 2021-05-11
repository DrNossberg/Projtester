/*
** EPITECH PROJECT, 2018
** FASTAtools
** File description:
** clean the momory used by the FASTAtools prog
*/

#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "argd_struct.h"

void ar_free(char **array, int arlen) {
    if (!array)
        return;
    for (int i = 0; array[i] || i < arlen; i++)
        if (array[i])
            free(array[i]);
    free(array);
}

void mr_free(clname_t *clname) {
    clname_t *prev;

    while (clname) {
        if (clname->chld_cl)
            mr_free(clname->chld_cl);
        prev = clname;
        clname = clname->next;
        free(prev->test_name);
        ar_free(prev->path, prev->pathlen);
        ar_free(prev->args, 0);
        free(prev->res);
        free(prev);
    }
}

void free_argd_data(argd_t *arg_data) {
    if (!arg_data)
        return;
    free(arg_data->options);
    free(arg_data->test_dir);
    if (arg_data->exec)
        free(arg_data->exec);
    free(arg_data);
}
