/*
** EPITECH PROJECT, 2018
** projTester
** File description:
** add slash 
*/

#include <string.h>
#include "prototypes.h"

char *add_slash(char *path)
{
	int len = strlen(path);

	if (path[len - 1] != '/')
		path = stradd(path, "/", 0);
	return (path);
}
