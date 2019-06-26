/*
** EPITECH PROJECT, 2018
** projTester
** File description:
** display the help page of the proj tester
*/

#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"

void display_help(void)
{
    puts("USAGE:");
    puts("\t./projTester TRD [BFT] [outputFile]/[option]\n");
    puts("DESCRIPTION:");
    printf("\t%s", "TRD");
    printf("\t\t%s\n", "root directory of all the tests");
    printf("\t%s", "BFT");
    printf("\t\t%s\n", "binary file to be tested");
    printf("\t%s", "outputFile");
    printf("\t%s\n", "file in witch the ressult is printed");
    printf("\t%s\n", "Option :");
    display_options();
}

void display_options(void)
{
    printf("\t\t-h\t%s\n", "help; display this help");
    printf("\t\t-s\t%s\n", "silence; don't print passed tests");
    printf("\t\t-l\t%s%s\n", "debugging; display the name",
    " of all failed tests");
    printf("\t\t-v\t%s%s\n", "optimisation; execute valgrind on all test",
    "IN BUILDING");
    printf("\t\t-f\t%s\n", "failed; print details of failed tests");
    printf("\t\t-d\t%s\n", "details; print details of all tests");
}
