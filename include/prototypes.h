/*
** EPITECH PROJECT, 2018
** projjTester
** File description:
** contain the prototypes of the projjTester functions
*/

#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_

#include <stdio.h>
#include <sys/types.h>

#include "struct.h"

/* parsing */
int parse_entry(int argc, char *argv[], int *options);
void fill_option_tab(char *argv[], int *options);
void catch_option(int *opt, char *argv);

/*tree*/
clname_t *build_tree(char *folder_name);
clname_t *tree(char *path, int basepathlen);
clname_t *do_recursive(clname_t *node, struct dirent *file,
char *path, int basepathlen);
int my_filter_function(const struct dirent *item);

/*fill_node_info*/
clname_t *read_test(clname_t *node, char *path);
int open_file(char *way, char *file_name, FILE **fd);

/*utils/*/
    /*cl_utils*/
    clname_t *add_clname_node(clname_t *p_head, char *str, int len);
    clname_t *init_cl(void);

    /*add_slash*/
    char *add_slash(char *path);

/*get/*/
char **get_test_attribut(FILE *fd);
char *get_next_arg(char **str);

/*get_test_result*/
char *get_test_res(FILE *fd);

void display_tree(clname_t *clname, int space);
void print_with_space(int n, char *str);
void mr_free(clname_t *clname);
clname_t *link_node_tocl(clname_t *p_head, clname_t *node);
char *is_in_cd(clname_t *cd_tree, char *path, char *function);
char *is_innode(char *path, char *filename, char *function);
char *launch_child(clname_t *node, char *path, char *function,
char **retour);
char **str_to_word_array(char const *str, char s);
char *my_getpath(char **env);
char *find_the_right_path(char **arpath, char *instruction);
char **my_path_to_ar(char *path);
char **full_with_slash(char **arpath);
void ar_free(char **array);
char *is_in_path(char **env, char *function);
int execute_test(clname_t *cd_tree, char *funct,
char *f_path, int *options);
void exec_command(clname_t *node, char *funct,
char *function_path, int *options);
char **get_path(char *path);
int count_path_node(char *path);
int count_argnbr(char *str);
void display_info(clname_t *node, int *options, char *buffer);
void display_help(void);
void redirect_output(int argc, char *argv[]);
void display_folder_name(char *path);
void child_process(int *fd, clname_t **node, char *funct);
int parent_process(int *fd, pid_t pid, int status, char *buffer);
void compare_test_res(clname_t *node, char *buffer,
int *options, int nbytes);
pid_t create_pid(int *fd);
int count_nbrofnode(clname_t *cd_tree, int nbr, int *nbr_ofsuccess);
void summarize(clname_t *cd_tree, int list);
void display_options(void);

int add_valgrind(char **function, int *options);
#endif /* PROTOTYPES_H_ */
