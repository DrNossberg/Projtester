/*
** EPITECH PROJECT, 2018
**      projTester
** File description:
**      display the help page of the proj tester
*/

#include <stdio.h>
#include <stdlib.h>

#include "prototypes.h"

//TODO add color

void display_help(void) {
    puts("NAME:");
    printf("\t%s\n", "projTester");
    display_usage();
    display_description();
    display_options();
    display_example();
    puts("Check the README.md for more informations\n");
    // display_credits();
}

void display_usage(void) {
    puts("\nUSAGE:");
    puts("\t./projTester [option] TRD [BFT]");
}

void display_description(void) {
    puts("\nDESCRIPTION:");
    printf("\t%s\t\t\t%s\n", "option", "optional parameters ; use to tweak the program behaviour (see next section)");
    printf("\t%s\t\t\t%s\n", "TRD", "tests root directory ; all tests files in this directory will be tested");
    printf("\t%s\t\t\t%s\n", "BFT", "binary file to be tested ; can be a command (the program will look for it in your PATH) or an exe");
    // printf("\t%s\t\t%s\n\n", "outputFile", "file in witch the ressult is printed");
}

void display_options(void) {
    puts("\nOPTIONS :");
    printf("\t -h  %s\t:\t%s\n", "help   ", "display help");
    printf("\t -s  %s\t:\t%s\n", "silence", "don't print passed tests");
    printf("\t -l  %s\t:\t%s%s\n", "debugging", "display the name",
    " of all failed tests");
    printf("\t -c  %s\t:\t%s\n", "color", "colored output");
    printf("\t -f  %s\t:\t%s\n", "failed", "print details of failed tests");
    printf("\t -d  %s\t:\t%s\n", "details", "print details of all tests");
    // printf("\t  -v   %s\t:\t%s\n", "valgrind", "execute valgrind on all test");
}

void display_example(void) {
    puts("\nEXAMPLE :");
    printf("\t%s\n", "./projTester -csf TestDirectory/ echo");
}