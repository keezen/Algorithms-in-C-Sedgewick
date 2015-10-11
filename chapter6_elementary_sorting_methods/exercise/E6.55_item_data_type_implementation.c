/*
** Implemention of the first-class item ADT, in which the item
** is a vector of d integers.
*/
#include<stdio.h>
#include<stdlib.h>
#include"item.h"

#define DIMENSION 3

struct ITEM{
	int vector[DIMENSION];
};

item_t rand_item(void)
{
	int i;
	item_t new=malloc(sizeof(*new));

	for(i=0;i<DIMENSION;i++){
		(new->vector)[i]=rand()%10;
	}

	return(new);
}

int scan_item(item_t *px)
{
	int i;

	*px=malloc(sizeof(**px));

	for(i=0;i<DIMENSION;i++){
		scanf("%d",&((*px)->vector)[i]);
	}
}

void print_item(item_t x)
{
	int i;

	putchar('(');
	for(i=0;i<DIMENSION;i++){
		printf("%d",(x->vector)[i]);
		if(i != DIMENSION-1)
			putchar(',');
	}
	putchar(')');
}

/*
** Compare two vectors, first compare the first components, if the
** first are equal, then compare the second components, and so forth.
*/
int compare_item(item_t a,item_t b)
{
	int i;
	int ka,kb;

	for(i=0;i<DIMENSION;i++){
		if((ka=(a->vector)[i]) != (kb=(b->vector)[i])){
			return(ka-kb);
		}
	}

	return(0);
}

void swap_item(item_t *pa,item_t *pb)
{
	item_t t;

	t=*pa;
	*pa=*pb;
	*pb=t;
}
