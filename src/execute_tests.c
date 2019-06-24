/*
** EPITECH PROJECT, 2018
** projTester
** File description:
** execute all test on the gien binary
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "prototypes.h"

int execute_test_tree(clname_t *cd_tree, char *f_path, int *options)
{
	char buffer[BUF_SIZE];
	clname_t *node = cd_tree;

	for (; node && node->next; node = node->next) {
		if (!node->test_name)
			continue;
		if (node->chld_cl)
			execute_test_tree(node->chld_cl, f_path, options);
		else {
			execute_test(node->args, f_path, buffer);
			if (!strcmp(node->res, buffer))
				node->success = 1;
			display_info(node, options, buffer);
		}
	}
	return (0);
}

void execute_test(char **args, char *function_path, char *buffer)
{
	int status = 0;
	int fd[2];
	pid_t pid = create_pid(fd);

	switch (pid) {
		case -1:
			fprintf(stderr, "Fork fail: %s", strerror(errno));
			exit(84);
		case 0:
			run_tested_prog(fd, function_path, args, &status);
			break;
		default:
			get_test_result(fd, pid, status, buffer);
			close(fd[PIP_READ]);
	}
}

void run_tested_prog(int *fd, char *function_path,
	char **args, int *status)
{
	close(fd[PIP_READ]);
	dup2(fd[PIP_WRITE], STDOUT_FILENO);
	*status = execv(function_path, args);
	if (*status == -1) 
		exit(84);
}

int get_test_result(int *fd, pid_t pid, int status, char *buffer)
{
	int nbytes = 0;

	close(fd[PIP_WRITE]);
	do {
		if (waitpid(pid, &status, 0) == -1)
			exit(84);
	} while (!WIFEXITED(status));
	memset(buffer, '\0', BUF_SIZE - 1);
	nbytes = read(fd[PIP_READ], buffer, BUF_SIZE - 1);
	if (nbytes == -1) {
		fprintf(stderr, "IO Error while reading test result, %s\n", strerror(errno));
		return (-1);
	}
	buffer[nbytes - 1] = '\0';
	close(fd[PIP_READ]);
	return (nbytes);
}
