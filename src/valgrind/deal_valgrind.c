/*
** EPITECH PROJECT, 2018
** projTester
** File description:
** function who allow projTester to supporte valgrind
*/

#include <string.h>
#include <stdlib.h>
#include "stradd.h"
#include "prototypes.h"

int add_valgrind(char **function, char *options)
{
    char *temp;
    if (!options[VALG])
        return (1);
    temp = strdup(*function);
    *function = stradd("valgrind ", temp);
    free(temp);
    return(1);
}
