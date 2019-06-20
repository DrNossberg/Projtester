/*
** EPITECH PROJECT, 2018
** FASTAtools
** File description:
** display differents things
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <struct.h>
#include "prototypes.h"

void display_tree(clname_t *clname, int space)
{
	clname_t *node = clname;

	if (!node)
		return;
	for (; node->next; node = node->next) {
		print_with_space(space, node->str);
		if (node->chld_cl) {
			puts("/");
			display_tree(node->chld_cl, space + 5);
		}
		else if (node->next)
			putchar('\n');
	}
}

void display_info(clname_t *node, int *options, char *buffer)
{
	int len = strlen(node->str);

	if (node->success && options[SILENCE])
		return;
	for (int i = node->basepathlen; node->path[i]; i++)
		printf("[%s] ", node->path[i]);
	for (int i = 0; i < len - 4; i++)
		printf("%c", node->str[i]);
	printf(": ");
	if (node->success && !options[SILENCE])
		printf("%sOK!%s\n", "\x1b[32m", "\x1b[0m");
	else
		printf("%sKO^%s\n", "\x1b[31m", "\x1b[0m");
	if ((options[FAIL] && !node->success) || options[DETAIL])
		printf("%sExpected:%s\n%s%s\nBut got:\n%s%s\n\n",
		"\x1b[34m", "\x1b[0m", node->res, "\x1b[34m", "\x1b[0m", buffer);
}

void print_with_space(int n, char *str)
{
	if (str) {
		while (n--)
			putchar('-');
		printf("%s", str);
	}
}

void display_folder_name(char *path)
{
	int i = strlen(path);
	int len = i - 1;

	for (; i && (path[i] != '/' || i == len); i--);
	if (path[i] == '/')
		i++;
	printf("%s%s", path + i, path[len] == '/' ? "\n" : "/\n");
}
