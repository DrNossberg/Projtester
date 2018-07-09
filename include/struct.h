/*
** EPITECH PROJECT, 2018
** FASTAtools
** File description:
** contain the struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <dirent.h>

#define SILENCE 0
#define LIST 1
#define PIP_READ 0
#define PIP_WRITE 1
#define BUF_SIZE 4096

typedef struct clname_s {
	char *str;
	char **path;
	char **args;
	char *res;
	int basepathlen;
	struct clname_s *chld_cl;
	struct clname_s *next;
	int success;
} clname_t;

#endif /* STRUCT_H_ */