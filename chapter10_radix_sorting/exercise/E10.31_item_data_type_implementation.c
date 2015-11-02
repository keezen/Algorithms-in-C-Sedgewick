#include<stdio.h>
#include"radix.h"
#include"item.h"

void swap_item(item_t *a,item_t *b)
{
	int i;
	char t;

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
		if((*a)[i] != (*b)[i]){
			return((*a)[i]-(*b)[i]);
		}
	}

	return(0);
}

void print_item(item_t *x)
{
	int i;

	putchar('(');
	for(i=0;i<bytesword-1;i++){
		if((*x)[i]==0){
			printf("%d,",(*x)[i]);
		}else{
			printf("%c,",(*x)[i]);
		}
	}

	if((*x)[i]==0){
		printf("%d)",(*x)[i]);
	}else{
		printf("%c)",(*x)[i]);
	}
}

