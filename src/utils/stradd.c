/*
** EPITECH PROJECT, 2018
** my_stradd
** File description:
** add a str to the end of an other one
*/

#include <stdlib.h>
#include <string.h>

#include "stradd.h"

char *strfadd(char *str_a, char *str_b, int free_status)
{
    return (__stradd(str_a, str_b, free_status));
}

char *stradd(char *str_a, char *str_b)
{
    return (__stradd(str_a, str_b, 0));
}

char *__stradd(char *str_a, char *str_b, int free_status)
{
    const size_t len_a = strlen(str_a);
    const size_t len_b = strlen(str_b);
    char *result = malloc(len_a + len_b + 1);

    if (!result)
        return (NULL);
    memcpy(result, str_a, len_a);
    memcpy(result + len_a, str_b, len_b + 1);
    if (free_status == FREE_STRA || free_status == FREE_STR)
        free(str_a);
    if (free_status == FREE_STRB || free_status == FREE_STR)
        free(str_b);
    return (result);
}
