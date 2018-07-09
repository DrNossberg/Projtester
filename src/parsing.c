/*
** EPITECH PROJECT, 2018
** FASTAtools
** File description:
** parse the given file into an array
*/

#include <string.h>
#include <stdlib.h>
#include "prototypes.h"

void fill_option_tab(int argc, char *argv[], int *options)
{
	if (argc < 4)
		return;
	if (argv[3][0] != '-' || !argv[3][1])
		return;
	if (strlen(argv[3]) == 2) {
		options[SILENCE] = 1;
		options[LIST] = 1;
	}
	options[SILENCE] = (argv[3][1] == 's') ? 1 : 0;
	options[LIST] = (argv[3][1] == 'l') ? 1 : 0;
}

int parse_entry(int argc, char *argv[], int *options)
{
	if (argc > 6 || argc < 2)
		return (84);
	if (!strcmp("-h", argv[1])) {
		display_help();
		exit(0);
	}
	fill_option_tab(argc, argv, options);
	return (0);
}
