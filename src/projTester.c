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

void do_test(clname_t *cd_tree, char *function, char **env, int *options)
{
	char *funct_path = is_in_cd(cd_tree, ".", function);

	funct_path = is_in_path(env, function);
	if (!funct_path)
		exit(84);
	if (!add_valgrind(&funct_path, options))
		return;
	if (execute_test(cd_tree, function, funct_path, options))
		return;
	summarize(cd_tree, options[LIST]);
	free(funct_path);
	return;
}

int main(int argc, char *argv[], char **env)
{
	clname_t *test_dir;
	int options[] = {'s', 'l', 'v', 'd', 'f', '\0'};

	if (parse_entry(argc, argv, options)) {
		fprintf(stderr, "Invalid intput, retry with -h for more informations.\n");
		return (84);
	}
	test_dir = build_tree(argv[1]);
	if (!test_dir)
		return (84);
	if (argc == 2) {
		display_folder_name(argv[1]);
		display_tree(test_dir, 5);
	} else
		do_test(test_dir, argv[2], env, options);
	mr_free(test_dir);
	return (0);
}
