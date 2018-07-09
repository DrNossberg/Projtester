/*
** EPITECH PROJECT, 2018
** my_stradd
** File description:
** add a str to the end of an other one
*/

#include <stdlib.h>
#include <string.h>

char *stradd(char *a, char *b, int freea)
{
	int len = strlen(a) + strlen(b);
	char *temp = malloc(sizeof(char) * (len + 1));

	if (!temp) return (NULL);
	temp = memset(temp, '\0', len);
	temp = strcat(strcat(temp, a), b);
	if (freea)
		free(a);
	return (temp);
}
