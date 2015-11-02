#ifndef ITEM_H
#define ITEM_H

#include"radix.h"
typedef char item_t[bytesword];

void swap_item(item_t *a,item_t *b);
void copy_item(item_t *a,item_t *b);
int compare_item(item_t *a,item_t *b);
void print_item(item_t *x);

#endif
