/*
** Implementation for item long data type interface.
*/
#include<stdio.h>
#include<stdlib.h>
#include"item.h"

item_t rand_item(void)
{
	return((long)rand()%100);
}

int scan_item(item_t *px)
{
	return(scanf("%ld",px));
}

void print_item(item_t x)
{
	printf("%ld",x);
}

int compare_item(item_t a,item_t b)
{
	return((int)(a-b));
}

void swap_item(item_t *pa,item_t *pb)
{
	item_t t;

	t=*pa;
	*pa=*pb;
	*pb=t;
}
