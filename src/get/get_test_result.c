/*
** EPITECH PROJECT, 2018
** projTester
** File description:
** compare the result of a test to what it sould be
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *get_test_res(FILE *fd)
{
    size_t n = 0;
    char *buffer = NULL;
    char *temp = NULL;

    getdelim(&buffer, &n, '\0', fd);
    if (strlen(buffer) <= 4)
        return (NULL);
    temp = strdup(buffer + 4);
    free(buffer);
    return (temp);
}
