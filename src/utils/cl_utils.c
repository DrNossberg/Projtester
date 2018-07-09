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

	if (!node)
		return (NULL);
	node->str = NULL;
	node->next = NULL;
	node->path = NULL;
	node->args = NULL;
	node->res = NULL;
	node->chld_cl = NULL;
	node->success = 0;
	return (node);
}

clname_t *add_clname_node(clname_t *p_head, char *str, int len)
{
	clname_t *node = init_cl();

	if (!node)
		return (NULL);
	node->str = strdup(str);
	if (!node->str)
		return (NULL);
	node->next = p_head;
	node->basepathlen = len;
	if (!p_head)
		return (node);
	p_head = node;
	return (p_head);
}

clname_t *sort_child(clname_t *node)
{
	if (node->chld_cl)
		while (is_arranged(node->chld_cl))
			node->chld_cl = bubble_sort(node->chld_cl);
	return (node);
}

int is_arranged(clname_t *p_head)
{
	clname_t *node = p_head;

	while (node->next) {
		if (node->next->str && strcmp(node->str, node->next->str) > 0)
			return (1);
		node = sort_child(node);
		node = node->next;
	}
	return (0);
}

clname_t *bubble_sort(clname_t *p_head)
{
	clname_t *node = p_head;
	clname_t *prev = p_head;
	clname_t *temp = p_head;

	while (node && node->next) {
		if (strcmp(node->str, node->next->str) > 0) {
			p_head = (p_head == node) ? node->next : p_head;
			temp = node->next;
			prev->next = temp;
			node->next = temp->next;
			temp->next = node;
			return (p_head);
		}
		prev = node;
		node = node->next;
	}
	return (p_head);
}
