/*
** EPITECH PROJECT, 2018
** projTester
** File description:
** main file of the projTester
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "prototypes.h"

void do_test(clname_t *test_tree, char *function, char **env, char *options)
{
    char *funct_path = is_in_cd(test_tree, ".", function);

    funct_path = is_in_path(env, function);
    if (!funct_path) {
        fprintf(stderr, "Executable passed as argument hasn't been found : %s\n", function);
        exit(84);
    }
    // if (!add_valgrind(&funct_path, options))
        // return;
    if (execute_test_tree(test_tree, funct_path, options))
        return;
    summarize(test_tree, options[LIST]);
    free(funct_path);
    return;
}

int projTester(argd_t *arg_data, char **env)
{
    clname_t *test_tree = build_tree(arg_data);

    if (!test_tree)
        return (84);
    if (!arg_data->exec)
        display_tree(arg_data->test_dir, test_tree, DOT_NBR);
    else
        do_test(test_tree, arg_data->exec, env, arg_data->options);
    mr_free(test_tree);
    return (0);
}

argd_t *init_argd_data(void)
{
    argd_t *tmp =  malloc(sizeof(argd_t));

    if (!tmp) {
        fprintf(stderr, "%s\n", "malloc error");
        return (NULL);
    }
    tmp->options         = NULL;
    tmp->test_dir         = NULL;
    tmp->test_dir_len     = 0;
    tmp->exec             = NULL;
    return (tmp);
}

int main(int argc, char *argv[], char **env)
{
    argd_t *arg_data = init_argd_data();
    int ret = 0;

    if (!arg_data)
        return (84);
    if (parse_entry(argc, argv, arg_data)) {
        free(arg_data);
        return (84);
    }
    ret = projTester(arg_data, env);
    free(arg_data);
    return (ret);
}
