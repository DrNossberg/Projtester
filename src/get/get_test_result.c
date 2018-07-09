/*
** EPITECH PROJECT, 2018
** projTester
** File description:
** compare the result of a test to what it sould be
*/

#include <string.h>
#include <stdlib.h>

char *get_test_res(char *buffer)
{
	char *temp = buffer;

	while (*temp && *temp != ':')
		temp++;
	if (*temp)
		temp++;
	return (strdup(temp));
}
