/*
** EPITECH PROJECT, 2019
** projTester
** File description:
** define the structure who contain infos about the program args
*/

#ifndef ARGV_STRUCT_H
#define ARGV_STRUCT_H
    
    #define TESTFILE_PATTERN   "*.tdf"


    #define OPTS "+slvdfch"

    #define SILENCE         1
    #define LIST            2
    #define VALG            3
    #define DETAIL          4
    #define FAIL            5
    #define COLORED_OUTPUT  6
    #define HELP            7

    #define OPT_NBR         7

    typedef struct argv_data_s{
        char *options;
        
        /*lenght (in folder) of the test directory passed as arg*/
        char *test_dir;
        int test_dir_len;
        char *exec;
    } argd_t;

#endif /*ARGV_STRUCT_H*/