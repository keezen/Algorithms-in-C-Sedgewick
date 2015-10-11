/*
** This code provides implementation of the functions
** defined in the array data type interface, using some
** operations defined in item.h.
*/
#include<stdlib.h>
#include<stdio.h>
#include"array.h"
#include"item.h"

item_t *create_array(int N)
{
	item_t *array=malloc(N*sizeof(item_t));

	return(array);
}

void randinit_array(item_t *array,int N)
{
	int i;

	for(i=0;i<N;i++){
		array[i]=rand_item();
	}
}

void scaninit_array(item_t *array,int *pN)
{
	int i;

	for(i=0;i<*pN;i++){
		if(scan_item(&array[i]) == EOF){
			break;
		}
	}

	*pN=i;
}

void print_array(item_t *array,int left,int right)
{
	int i;

	for(i=left;i<=right;i++){
		print_item(array[i]);
		putchar(' ');
	}
	putchar('\n');
}

void sort_array(item_t *array,int left,int right)
{
	qsort(array,right-left+1,sizeof(item_t),compare_item);
}
