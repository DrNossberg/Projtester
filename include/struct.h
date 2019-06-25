/*
** EPITECH PROJECT, 2018
** FASTAtools
** File description:
** contain the struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

	#include <dirent.h>

	#define SILENCE		0
	#define LIST		1
	#define VALG		2
	#define DETAIL		3
	#define	FAIL		4
	#define	COLORED_OUTPUT		5

	
	#define PIP_READ	0
	#define PIP_WRITE	1
	#define BUF_SIZE	4096

	#define DOT_NBR		5
	#define SEPARATOR 	'-'

	typedef struct clname_s {
		char *test_name;
		char **args;
		char *res;

		char **path;
		int pathlen;

		/*lenght (in folder) of the test directory passed as arg*/
		int arg_pathlen;

		int success;
		struct clname_s *chld_cl;
		struct clname_s *next;
	} clname_t;

#endif /* STRUCT_H_ */