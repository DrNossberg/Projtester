/*
** EPITECH PROJECT, 2019
** projTester
** File description:
** define the structure who contain infos about the program args
*/

#ifndef ARGV_STRUCT_H
#define ARGV_STRUCT_H

    typedef struct argv_data_s{
        char *options;
        
        /*lenght (in folder) of the test directory passed as arg*/
        char *test_dir;
        int test_dir_len;
        char *exec;
    } argd_t;

#endif /*ARGV_STRUCT_H*/