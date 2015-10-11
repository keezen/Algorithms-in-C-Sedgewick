/*
** This interface for array data type, defines some functions for
** arrays of abstract items: initialize random values, initialize 
** values read from standard input, print the array contents, and
** sort the array.
*/
#ifndef ARRAY_H
#define ARRAY_H

#include"item.h"

item_t *create_array(int N);
void randinit_array(item_t *array,int N);
void scaninit_array(item_t *array,int *pN);
void print_array(item_t *array,int left,int right);
void sort_array(item_t *array,int left,int right);

#endif
