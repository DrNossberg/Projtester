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

int execute_test(clname_t *cd_tree, char *f_path, int *options)
{
	clname_t *node = cd_tree;

	for (; node && node->next; node = node->next) {
		if (!node->str)
			continue;
		if (node->chld_cl)
			execute_test(node->chld_cl, f_path, options);
		else
			exec_command(node, f_path, options);
	}
	return (0);
}

void exec_command(clname_t *node, char *function_path, int *options)
{
	int status = 0;
	int fd[2];
	pid_t pid = create_pid(fd);
	char buffer[BUF_SIZE];
	printf("path : %s\n", function_path);

	switch (pid) {
		case -1:
			puts("Fork fail");
			perror("fork");
			exit(84);
		case 0:
			child_process(fd);
			status = execv(function_path, node->args);
			if (status == -1) 
				exit(84);
			break;
		default:
			get_test_result(fd, pid, status, buffer);
			compare_test_res(node, buffer, options);
			close(fd[PIP_READ]);
	}
}

void child_process(int *fd)
{
	close(fd[PIP_READ]);
	dup2(fd[PIP_WRITE], STDOUT_FILENO);
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

void compare_test_res(clname_t *node, char *buffer, int *options)
{
	if (!strcmp(node->res, buffer))
		node->success = 1;
	display_info(node, options, buffer);
	fflush(stdout);
}
