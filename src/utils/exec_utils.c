/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** contain the basic function to execute the programme
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

pid_t create_pid(int *fd)
{
	if (pipe(fd) == -1) {
		perror("Pipe fail while exec_command");
		exit(84);
	}
	return (fork());
}
