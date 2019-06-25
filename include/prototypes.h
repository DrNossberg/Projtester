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
clname_t *build_tree(char **argv);
clname_t *tree(char *path, char *function, int test_dir_len);
int my_scandir(char *path, struct dirent ***namelist);
int my_filter_function(const struct dirent *item);


/*fill_node_info*/
clname_t *create_test_node(clname_t *p_head, char *function, char *test_name, char *path);
int open_file(char *way, char *file_name, FILE **fd);

/*utils/*/
    /*my_free*/
    void mr_free(clname_t *clname);
    void ar_free(char **array, int arlen);

    /*cl_utils*/
    clname_t *add_clname_node(clname_t *p_head, char *str);
    clname_t *init_cl(void);

    /*add_slash*/
    char *add_slash(char *path);

/*get/*/
    /*get_test_attribut*/
    char **get_test_attribut(FILE *fd);
    /*get_test_result*/
    char *get_test_res(FILE *fd);
    /*get_path*/
    char **get_path(char *path, int *arlen);
    int count_path_folder(char *path);

/*display/*/
    /*display*/
    void display_tree(char *test_folder, clname_t *clname, int space);
    void display_path(int n, char *str);

/*execute_test*/
int execute_test_tree(clname_t *cd_tree, char *f_path, int *options);
void execute_test(char **args, char *function_path, char *buffer);
void run_tested_prog(int *, char *, char **, int *);
int get_test_result(int *fd, pid_t pid, int status, char *buffer);


char *is_in_cd(clname_t *cd_tree, char *path, char *function);
char *is_innode(char *path, char *filename, char *function);
char *launch_child(clname_t *node, char *path, char *function,
char **retour);
char **str_to_word_array(char const *str, char s);
char *my_getpath(char **env);
char *find_the_right_path(char **arpath, char *instruction);
char **my_path_to_ar(char *path);
char *is_in_path(char **env, char *function);
int count_argnbr(char *str);
void display_info(clname_t *node, int *options, char *buffer);
void display_help(void);
void display_folder_name(char *path);
pid_t create_pid(int *fd);
int count_nbrofnode(clname_t *cd_tree, int nbr, int *nbr_ofsuccess);
void summarize(clname_t *cd_tree, int list);
void display_options(void);

int add_valgrind(char **function, int *options);
#endif /* PROTOTYPES_H_ */
