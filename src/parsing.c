/*
** EPITECH PROJECT, 2018
** ProjTester
** File description:
** parse the given file into an array
*/

#include <string.h>
#include <stdlib.h>
#include "prototypes.h"

int parse_entry(int argc, char *argv[], int *options)
{
	if (argc < 2)
		return (84);
	if (!strcmp("-h", argv[1])) {
		display_help();
		exit(0);
	}
	if (argc > 2)
		fill_option_tab(argv, options);
	return (0);
}

void fill_option_tab(char *argv[], int *options)
{
	int n = 0;

	for (int i = 3; argv[i]; i++) {
		if (argv[i][0] != '-' || !argv[3][1])
			exit(84);
		for (n = 0; options[n]; n++)
			catch_option(&options[n], argv[i]);
	}
	for(n = 0; options[n]; n++)
		if (options[n] != 1)
			options[n] = 0;
}

void catch_option(int *opt, char *argvi)
{
	for (int n = 0; argvi[n]; n++)
		if (*opt == argvi[n])
			*opt = 1;
}
