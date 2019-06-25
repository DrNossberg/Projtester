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
#include "colors.h"

#define COLORED(Y, X) Y[COLORED_OUTPUT] ? X : "\0"

void display_tree(char *test_folder, clname_t *clname, int char_nbr)
{
	clname_t *node = clname;

	if (test_folder)
		display_folder_name(test_folder);
	for (; node && node->next; node = node->next) {
		display_path(char_nbr, node->test_name);
		if (node->chld_cl) {
			puts("/");
			display_tree(NULL, node->chld_cl, char_nbr + 5);
		} else if (node->next)
			putchar('\n');
	}
}

void display_info(clname_t *node, int *options, char *buffer)
{
	int len = strlen(node->test_name);

	if (node->success && options[SILENCE])
		return;
	for (int i = node->arg_pathlen; node->path[i]; i++)
		printf("[%s%s%s] ", COLORED(options, BOLD_BLUE), node->path[i], WHITE);
	for (int i = 0; i < len - 4; i++)
		printf("%c", node->test_name[i]);
	printf(": ");
	if (node->success && !options[SILENCE])
		printf("%sOK!%s\n", COLORED(options, GREEN), WHITE);
	else
		printf("%sKO^%s\n", COLORED(options, RED), WHITE);
	if ((options[FAIL] && !node->success) || options[DETAIL])
		printf("%sExpected:%s\n%s%s\nBut got:\n%s%s\n\n",
		COLORED(options, BLUE), WHITE, node->res, COLORED(options, BLUE), WHITE, buffer);
}

void display_path(int n, char *str)
{
	if (str) {
		while (n--)
			putchar(SEPARATOR);
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
