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

clname_t *build_tree(char *folder_name)
{
	int baselen = 0;
	clname_t *cl_name = NULL;

	for (int i = 0; folder_name[i]; i++)
		if (folder_name[i] == '/')
			baselen++;
	cl_name = tree(folder_name, baselen);
	if (!cl_name)
		return (NULL);
	cl_name = sort_tree(cl_name);
	if (!cl_name)
		return (NULL);
	return (cl_name);
}

void do_test(clname_t *cd_tree, char *function, char **env, int *options)
{
	char *funct_path = is_in_cd(cd_tree, ".", function);

	if (!funct_path)
		funct_path = is_in_path(env, function);
	if (!funct_path)
		exit(84);
	if (execute_test(cd_tree, function, funct_path, options[SILENCE]))
		return;
	summarize(cd_tree, options[LIST]);
	free(funct_path);
	return;
}

int main(int argc, char *argv[], char **env)
{
	clname_t *test_dir;
	int options[] = {0, 0};

	if (parse_entry(argc, argv, options))
		return (84);
	if (argv[1][0] == '.' && argv[1][1] == '/')
		argv[1] += 2;
	test_dir = build_tree(argv[1]);
	if (argc == 2) {
		display_folder_name(argv[1]);
		display_tree(test_dir, 5);
	} else
		do_test(test_dir, argv[2], env, options);
	mr_free(test_dir);
	return (0);
}
