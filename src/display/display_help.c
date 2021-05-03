/*
** EPITECH PROJECT, 2018
**      projTester
** File description:
**      display the help page of the proj tester
*/

#include <stdio.h>
#include <stdlib.h>

#include "prototypes.h"

void display_help(void) {
    puts("NAME");
    puts("projTester");
    display_usage();
    display_description();
    display_options();
}

void display_usage(void) {
    puts("USAGE:");
    puts("\t./projTester TRD [BFT] [outputFile]/[option]\n");
}

void display_description(void) {
    puts("DESCRIPTION:");
    printf("\t%s\t\t\t%s\n", "TRD", "root directory of all the tests");
    printf("\t%s\t\t\t%s\n", "BFT", "binary file to be tested");
    printf("\t%s\t\t%s\n\n", "outputFile", "file in witch the ressult is printed");
}

void display_options(void) {
    printf("\t%s\n", "OPTIONS :");
    printf("\t  -h   %s\t:\t%s\n", "help   ", "display help");
    printf("\t  -s   %s\t:\t%s\n", "silence", "don't print passed tests");
    printf("\t  -l   %s:\t%s%s\n", "debugging", "display the name",
    " of all failed tests");
    printf("\t  -c   %s\t:\t%s\n", "color", "colored output");
    printf("\t  -f   %s\t:\t%s\n", "failed", "print details of failed tests");
    printf("\t  -d   %s\t:\t%s\n", "details", "print details of all tests");
    printf("\t  -v   %s\t:\t%s\n", "valgrind", "execute valgrind on all test");
}