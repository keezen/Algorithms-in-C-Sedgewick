#ifndef ARRAY_H
#define ARRAY_H

#include"item.h"

void randinit_array(item_t *array,int N);
void scaninit_array(item_t *array,int *pN);
void print_array(item_t *array,int left,int right);
void sort_array(item_t *array,int left,int right);
int check_sorted_array(item_t *array,int left,int right);

#endif
