/*
** EPITECH PROJECT, 2018
** ProjTester
** File description:
** parse the given file into an array
*/

#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>   /*stat*/
#include <unistd.h>     /*getopt*/
#include <errno.h>

#include "prototypes.h"

int parse_entry(int argc, char *argv[], argd_t *arg_data)
{
    char *opts = OPTS;

    if (argc < 2) {
        fprintf(stderr, "Invalid intput, retry with -h for more informations.\n");
        return (84);
    }
    arg_data->options = parse_opts(argc, argv, opts);
    if (!arg_data->options)
        return (84);
    if (arg_data->options[HELP]) {
        free_argd_data(arg_data);
        display_help();
        exit(0);
    }
    if (parse_TDR_BFT(argc, argv, arg_data))
        return (84);
    arg_data->test_dir_len = count_path_folder(arg_data->test_dir);
    return (0);
}

int find_position(char opts_tab[], char opt)
{
    for (int i = 0; opts_tab[i]; ++i)
        if (opts_tab[i] == opt)
            return (i);
    return (HELP);
}

char *parse_opts(int argc, char *argv[], char *opts)
{
    int curr;
    char *opts_tab = strdup(opts);

    if (!opts_tab) {
        fprintf(stderr, "Parse opts, : %s\n", strerror(errno));
        return (NULL);
    }
    while ((curr = getopt(argc, argv, opts)) != -1) {
        switch (curr) {
        case '?':
            display_help();
            free(opts_tab);
            return (NULL);
        default:
            opts_tab[find_position(opts_tab, curr)] = 1;
        }
    }
    for (int i = 0; opts_tab[i]; i++)
        opts_tab[i] = (opts_tab[i] > 1) ? 0 : opts_tab[i];
    return (opts_tab);
}

int parse_TDR_BFT(int argc, char *argv[], argd_t *arg_data)
{
    static const struct stat null_struct;
    struct stat stbuf;
    errno = 0;

    for (int i = 1; i < argc; ++i, errno = 0, stbuf = null_struct) {
        if (argv[i][0] == '-')
            continue;
        if (stat(argv[i], &stbuf) == -1)
            arg_data->exec = strdup(argv[i]);
        if (S_ISDIR(stbuf.st_mode))
            arg_data->test_dir = strdup(argv[i]);
    }
    if (!arg_data->test_dir) {
        display_help();
        return (84);
    }
    return (0);
}
