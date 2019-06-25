/*
** EPITECH PROJECT, 2018
** projTest
** File description:
** calculate and display the summary
*/

#include "prototypes.h"
#include "struct.h"

int count_nbrofnode(clname_t *cd_tree, int nbr, int *nbr_ofsuccess)
{
    clname_t *node = cd_tree;

    for (; node; node = node->next) {
        if (!node->test_name)
            continue;
        if (node->chld_cl)
            nbr = count_nbrofnode(node->chld_cl, nbr,
            nbr_ofsuccess);
        else {
            *nbr_ofsuccess += node->success;
            nbr += 1;
        }
    }
    return (nbr);
}

void list_all_failedtest(clname_t *cd_tree)
{
    clname_t *node = cd_tree;

    for (; node; node = node->next) {
        if (!node->test_name)
            continue;
        if (node->chld_cl)
            list_all_failedtest(node->chld_cl);
        if (!node->chld_cl && !node->success)
            printf("%s;", node->test_name);
    }
    return;
}

void summarize(clname_t *cd_tree, int list)
{
    int nbr_ofnode = 0;
    int nbr_ofsuccess = 0;
    int nbr_offails = 0;

    nbr_ofnode = count_nbrofnode(cd_tree, nbr_ofnode, &nbr_ofsuccess);
    nbr_offails = nbr_ofnode - nbr_ofsuccess;
    printf("\nSummary:\nPassed test : %d/%d - %d fails\n",
    nbr_ofsuccess, nbr_ofnode, nbr_offails);
    if (nbr_ofsuccess == nbr_ofnode)
        printf("\nAll test passed, congratulation!\n");
    if (list && nbr_offails) {
        printf("\n----------*\nFailed Test = ");
        list_all_failedtest(cd_tree);
        printf("\n");
    }
}
