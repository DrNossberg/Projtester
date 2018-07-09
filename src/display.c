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

void display_info(clname_t *node)
{
	int len = strlen(node->str);

	for (int i = node->basepathlen; node->path[i]; i++)
		printf("[%s] ", node->path[i]);
	for (int i = 0; i < len - 4; i++)
		printf("%c", node->str[i]);
	printf(": ");
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
	int i = 0;

	for (; path[i]; i++);
	for (; i > 0 && path[i] != '/'; i--);
	if (path[i] == '/')
		i++;
	printf("%s\n", path + i);
}

void display_help(void)
{
	puts("USAGE:");
	puts("\t./projTester TRD [BFT] [outputFile]/[option]\n");
	puts("DESCRIPTION");
	printf("\t%s", "TRD");
	printf("\t%s\n", "root directory of all the tests");
	printf("\t%s", "BFT");
	printf("\t%s\n", "binary file to be tested");
	printf("\t%s", "outputFile");
	printf("\t%s\n", "file in witch the ressult is printed");
	printf("\t%s", "option");
	printf("\t%s\n", "-s\tsilence; don't print passed tests");
	printf("\t%s\n", "-l\tlist the name of all failed tests");
	exit(0);
}
