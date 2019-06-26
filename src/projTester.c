/*
** EPITECH PROJECT, 2018
** projTester
** File description:
** main file of the projTester
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "prototypes.h"

int projTester(argd_t *arg_data, char **env)
{
    clname_t *test_tree = build_tree(arg_data->test_dir, arg_data);

    if (!test_tree)
        return (84);
    if (!arg_data->exec)
        display_tree(arg_data->test_dir, test_tree, DOT_NBR);
    else
        do_test(test_tree, arg_data, env);
    mr_free(test_tree);
    return (0);
}

int main(int argc, char *argv[], char **env)
{
    argd_t *arg_data = init_argd_data();
    int ret = 0;

    if (parse_entry(argc, argv, arg_data)) {
        free(arg_data);
        return (84);
    }
    ret = projTester(arg_data, env);
    free_argd_data(arg_data);
    return (ret);
}
