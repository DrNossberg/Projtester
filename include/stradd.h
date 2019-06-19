/*
** EPITECH PROJECT, 2018
** lib_c
** File description:
** contain the prototypes of the stradd functions
*/

#ifndef STRADD_HEADER
#define STRADD_HEADER

#define FREE_STRA 1
#define FREE_STRB 2
#define FREE_STR  3

char *strfadd(char *str_a, char *str_b, int free_status);
char *stradd(char *str_a, char *str_b);
char *__stradd(char *str_a, char *str_b, int free_status);

#endif /* STRADD_HEADER */
