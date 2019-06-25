/*
** EPITECH PROJECT, 2018
** projTester
** File description:
** return the arg wrote in the file passed as arg
*/

#include <string.h>
#include <stdlib.h>
#include <fcntl.h>


#include "prototypes.h"

char **get_args_line(char *buffer)
{
    int arglen = 2;
    char **arg = NULL;
    char *tmp = buffer;
    char *token;

    arglen += count_argnbr(buffer);
    arg = malloc(sizeof(char *) * (arglen + 1));
    if (!arg)
        return (NULL);
    for (int i = 0; i < arglen; i++)
        arg[i] = NULL;
    for (int i = 1; ; i++, tmp = NULL) {
        token = strtok(tmp, " ");
        if (!token) {
            arg[i] = NULL;
            break;
        }
        arg[i] = strdup(token);
    }
    return (arg);
}

char **get_test_attribut(FILE *fd)
{
    size_t n = 0;
    char **arg = NULL;
    char *buffer = NULL;

    getline(&buffer, &n, fd);
    buffer[strlen(buffer) - 1] = '\0';
    arg = get_args_line(buffer + 5);
    free(buffer);
    return (arg);
}

int count_argnbr(char *str)
{
    int arg_nbr = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == ' ')
            arg_nbr++;
    return (arg_nbr);
}
