/*
** EPITECH PROJECT, 2018
** FASTAtools
** File description:
** contain basic funct to deal with cl
*/

#include <string.h>
#include <stdlib.h>
#include "struct.h"
#include "prototypes.h"

clname_t *init_cl(void)
{
	clname_t *node = malloc(sizeof(clname_t));

	if (!node) {
		perror("malloc");
		exit(84);
	}
	node->str 	= NULL;
	node->next 	= NULL;
	node->path 	= NULL;
	node->args 	= NULL;
	node->res 	= NULL;
	node->chld_cl = NULL;
	node->success = 0;
	node->pathlen = 0;
	return (node);
}

clname_t *add_clname_node(clname_t *p_head, char *str)
{
	clname_t *node = init_cl();

	node->next = p_head;
	node->str = strdup(str);
	if (!node->str)
		return (NULL);
	return (node);
}
