/*
** EPITECH PROJECT, 2018
** FASTAtools
** File description:
** display differents things
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <struct.h>
#include <unistd.h>

#include "prototypes.h"
#include "colors.h"

#define COLORED(Y, X) Y[COLORED_OUTPUT] ? X : "\0"
#define COLORED_LINE(Y, VAR, X) Y[COLORED_OUTPUT] ? printf("%s%s%s", X, VAR, WHITE) : printf(VAR)

void display_tree(char *test_folder, clname_t *clname, int char_nbr)
{
    clname_t *node = clname;

    if (test_folder)
        display_folder_name(test_folder);
    for (; node && node->next; node = node->next) {
        display_path(char_nbr, node->test_name);
        if (node->chld_cl) {
            puts("/");
            display_tree(NULL, node->chld_cl, char_nbr + 5);
        } else if (node->next)
            putchar('\n');
    }
}

void display_info(clname_t *node,  argd_t *argd, char *buffer) {
    if (node->success && argd->options[SILENCE])
        return;
    // argd->test_dir_len -> //TODO could become an option
    for (int i = 0; node->path[i]; i++)
        printf("[%s%s%s] ", COLORED(argd->options, BOLD_BLUE), node->path[i], WHITE);
    printf("%.*s: ", (int) (strlen(node->test_name) - (strlen(TESTFILE_PATTERN) - 1)), node->test_name);
    if (node->success && !argd->options[SILENCE])
        COLORED_LINE(argd->options, "OK!\n", GREEN);
    else
        COLORED_LINE(argd->options, "KO^\n", RED);
    if ((argd->options[FAIL] && !node->success) || argd->options[DETAIL])
        printf("%sExpected:%s\n%s%s\nBut got:\n%s%s\n\n",
        COLORED(argd->options, BLUE), WHITE,
        node->res, COLORED(argd->options, BLUE), WHITE, buffer);
}

void display_path(int n, char *str) {
    if (str) {
        while (n--)
            putchar(SEPARATOR);
        printf("%s", str);
    }
}

void display_folder_name(char *path) {
    int i = strlen(path);
    int len = i - 1;

    for (; i && (path[i] != '/' || i == len); i--);
    if (path[i] == '/')
        i++;
    printf("%s%s", path + i, path[len] == '/' ? "\n" : "/\n");
}

// void display_parsed_info(argd_t *argd) {
//     printf("Exec : %s\n", arg_data->exec);
//     printf("Test_dir : %s\n", arg_data->test_dir);
//     for (int i = 1; i < OPT_NBR; i++)
//         printf("[%c] : %d ", OPTS[i], arg_data->options[i]);
//     puts(" ");
// }
