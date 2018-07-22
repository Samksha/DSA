#ifndef TODOT_H
#define TODOT_H

#include <stdio.h>

void bst_print_dot_null(int, int, FILE*);

void bst_print_dot_aux(Node, FILE*);

void bst_print_dot(Tree tree, FILE* stream);

#endif