/*
** EPITECH PROJECT, 2018
** projTester
** File description:
** return the array of the path of the current node
*/

#include <string.h>
#include <stdlib.h>
#include "prototypes.h"

char **get_path(char *path, int *arlen)
{
    int i = 0;
    int j;
    char **array = NULL;

    *arlen = count_path_folder(path);
    array = malloc(sizeof(char *) * (*arlen + 1));
    array[*arlen] = NULL;
    for (int k = 0; k < *arlen; k++) {
        while (path[i] && path[i] != '/')
            i++;
        i++;
        for (j = 0; path[i + j] && path[i + j] != '/'; j++);
        array[k] = (j > 0) ? strndup(path + i, j) : NULL;
    }
    return (array);
}

int count_path_folder(char *path)
{
    int len = 0;

    for (int i = 0; path[i]; i++)
        if (path[i] == '/')
            len++;
    return (len);
}
