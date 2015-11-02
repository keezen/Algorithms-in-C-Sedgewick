#include<stdio.h>
#include"radix.h"
#include"item.h"

void swap_item(item_t *a,item_t *b)
{
	int i;
	double t;

	for(i=0;i<bytesword;i++){
		t=(*a)[i];
		(*a)[i]=(*b)[i];
		(*b)[i]=t;
	}
}

void copy_item(item_t *a,item_t *b)
{
	int i;

	for(i=0;i<bytesword;i++){
		(*a)[i]=(*b)[i];
	}
}

int compare_item(item_t *a,item_t *b)
{
	int i;

	for(i=0;i<bytesword;i++){
		if((*a)[i]<(*b)[i]){
			return(-1);
		}
		if((*a)[i]>(*b)[i]){
			return(1);
		}
	}

	return(0);
}

void print_item(item_t *x)
{
	int i;

	putchar('(');
	for(i=0;i<bytesword-1;i++){
		printf("%.2f,",(*x)[i]);
	}
	printf("%.2f)",(*x)[i]);
}

