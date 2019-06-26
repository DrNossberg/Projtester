/*
** EPITECH PROJECT, 2019
** projTester
** File description:
** define the structure who contain infos about the program args
*/

#ifndef ARGV_STRUCT_H
#define ARGV_STRUCT_H
    
    #define OPTS "slvdfch"

    #define SILENCE         0
    #define LIST            1
    #define VALG            2
    #define DETAIL          3
    #define FAIL            4
    #define COLORED_OUTPUT  5
    #define HELP            6

    #define OPT_NBR         7

    typedef struct argv_data_s{
        char *options;
        
        /*lenght (in folder) of the test directory passed as arg*/
        char *test_dir;
        int test_dir_len;
        char *exec;
    } argd_t;

#endif /*ARGV_STRUCT_H*/