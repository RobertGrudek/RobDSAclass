#pragma once
#include "helperfunctions.h"

void add_bTree(bTree *b, bTree *_parent, char *buffer);
void print_bTree0(bTree b, int depth);
void print_bTree(bTree b);
void traverse_in_order(bTree *b);
bTree *MaxT(bTree *b);
void string_data_print(bTree b);
void parent_inorder(bTree *b);
bTree *nast_t(bTree *b);