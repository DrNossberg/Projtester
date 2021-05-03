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
#include <errno.h>      /*errno*/

#include "prototypes.h"

int parse_entry(int argc, char *argv[], argd_t *argd) {
    if (!(argd->options = strdup(OPTS))) {
        fprintf(stderr, "Malloc issue : %s\n", strerror(errno));
        return (84);
    }
    if (!parse_opts(argc, argv, argd))
        return (84);
    if (argc < 2 || !argd->test_dir || argd->options[HELP]) {
        free_argd_data(argd);
        display_help();
        exit(0);
    }
    argd->test_dir_len = count_path_folder(argd->test_dir);
    return (0);
}

int correct_opt_tab(char opts_tab[], char opt) {
    for (int i = 0; opts_tab[i]; ++i)
        if (opts_tab[i] == opt)
            return (i);
    return (HELP);
}

char *parse_opts(int argc, char *argv[], argd_t *argd) {
    for (int opt; (opt = getopt(argc, argv, OPTS)) != -1;)
        switch (opt) {
            case '?':
                fprintf(stderr, "Unknown option : %c", optopt);
                free(argd->options);
                return (NULL);
            default:
                argd->options[correct_opt_tab(argd->options, opt)] = 1;
        }
    for (int i = 0; argd->options[i]; i++)
        argd->options[i] = (argd->options[i] > 1) ? 0 : argd->options[i];
    if (optind < argc)
        argd->test_dir  = strdup(argv[optind]);
    if (optind + 1 < argc)
        argd->exec      = strdup(argv[optind + 1]);
    return (argd->options);
}
