/*
** EPITECH PROJECT, 2018
** projTester
** File description:
** compare the result of a test to what it sould be
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *get_test_res(FILE *fd) {
    char *buffer = NULL;
    char *temp = NULL;
    size_t n = 0;

    getdelim(&buffer, &n, '\0', fd);
    if (strlen(buffer) <= 4)
        temp = strdup("\0");
    else
        temp = strdup(buffer + 4);
    free(buffer);
    return (temp);
}
