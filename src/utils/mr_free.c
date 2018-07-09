/*
** EPITECH PROJECT, 2018
** FASTAtools
** File description:
** clean the momory used by the FASTAtools prog
*/

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

void ar_free(char **array)
{
	int i = 0;

	if (!array)
		return;
	for (; array[i + 1]; i++)
		free(array[i]);
	if (array[i])
		free(array[i]);
	free(array);
}

void mr_free(clname_t *clname)
{
	clname_t *prev = clname;

	while (clname) {
		if (clname->chld_cl)
			mr_free(clname->chld_cl);
		prev = clname;
		clname = clname->next;
		free(prev->str);
		ar_free(prev->path);
		ar_free(prev->args);
		free(prev->res);
		free(prev);
	}
}
