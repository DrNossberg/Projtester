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
#include "prototypes.h"

int execute_test(clname_t *cd_tree, char *funct,
char *f_path, int silence)
{
	clname_t *node = cd_tree;

	for (; node; node = node->next) {
		if (!node->str)
			continue;
		if (node->chld_cl)
			execute_test(node->chld_cl, funct, f_path, silence);
		else
			exec_command(node, funct, f_path, silence);
	}
	return (0);
}

void exec_command(clname_t *node, char *funct,
char *function_path, int silence)
{
	int status = 0;
	int fd[2];
	pid_t pid = create_pid(fd);
	char buffer[BUF_SIZE];

	switch (pid) {
	case -1:
		puts("Fork fail");
		exit(84);
	case 0:
		child_process(fd, &node, funct);
		status = execv(function_path, node->args);
		if (status == -1)
			exit(84);
		break;
	default:
		compare_test_res(node, buffer, silence,
		parent_process(fd, pid, status, buffer));
		close(fd[PIP_READ]);
	}
}

void child_process(int *fd, clname_t **node, char *funct)
{
	close(fd[PIP_READ]);
	dup2(fd[PIP_WRITE], STDOUT_FILENO);
	(*node)->args[0] = funct;
}

int parent_process(int *fd, pid_t pid, int status, char *buffer)
{
	int nbytes = 0;

	close(fd[PIP_WRITE]);
	do {
		if (waitpid(pid, &status, 0) == -1)
			exit(84);
	} while (!WIFEXITED(status));
	memset(buffer, '\0', BUF_SIZE - 1);
	nbytes = read(fd[PIP_READ], buffer, BUF_SIZE - 1);
	close(fd[PIP_READ]);
	return (nbytes);
}

void compare_test_res(clname_t *node, char *buffer,
int silence, int nbytes)
{
	if (nbytes == -1) {
		printf("IO Error\n");
		return;
	}
	buffer[nbytes - 1] = '\0';
	if (!strcmp(node->res, buffer)) {
		node->success = 1;
		if (!silence) {
			display_info(node);
			printf("%sOK!%s\n", "\x1b[32m", "\x1b[0m");
		}
	} else {
		display_info(node);
		printf("%sKO^%s\nExpected:\n%s%s\n", "\x1b[31m",
		"\x1b[34m", "\x1b[0m", node->res);
		printf("%sBut got:\n%s%s\n", "\x1b[34m", "\x1b[0m", buffer);
	}
	fflush(stdout);
}
