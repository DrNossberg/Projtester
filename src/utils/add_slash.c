/*
** EPITECH PROJECT, 2018
** projTester
** File description:
** add slash 
*/

#include <string.h>
#include "stradd.h"

char *add_slash(char *path)
{
    char *tmp = NULL;

    if (path[strlen(path) - 1] != '/')
        tmp = stradd(path, "/");
    else
        tmp = strdup(path); /* hum *kof* *kof* */
    return (tmp);
}
