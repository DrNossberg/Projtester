/*
** EPITECH PROJECT, 2018
** projTester
** File description:
** main file of the projTester
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "prototypes.h"

void do_test(clname_t *test_tree, char *function, char **env, int *options)
{
	char *funct_path = is_in_cd(test_tree, ".", function);

	// free(funct_path);
	funct_path = is_in_path(env, function);
	if (!funct_path)
		exit(84);
	if (!add_valgrind(&funct_path, options))
		return;
	if (execute_test_tree(test_tree, funct_path, options))
		return;
	summarize(test_tree, options[LIST]);
	free(funct_path);
	return;
}

int main(int argc, char *argv[], char **env)
{
	clname_t *test_tree;
	int options[] = {'s', 'l', 'v', 'd', 'f', 'c', '\0'};

	if (parse_entry(argc, argv, options)) {
		fprintf(stderr, "Invalid intput, retry with -h for more informations.\n");
		return (84);
	}
	test_tree = build_tree(argv);
	if (!test_tree)
		return (84);
	if (argc == 2)
		display_tree(argv[1], test_tree, 5);
	else
		do_test(test_tree, argv[2], env, options);
	mr_free(test_tree);
	return (0);
}
