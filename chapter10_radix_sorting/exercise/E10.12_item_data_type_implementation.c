#include<stdio.h>
#include"item.h"

void swap_item(item_t *a,item_t *b)
{
	item_t t;

	t=*a;
	*a=*b;
	*b=t;
}

void copy_item(item_t *a,item_t *b)
{
	*a=*b;
}

int compare_item(item_t a,item_t b)
{
	return(a-b);
}

void print_item(item_t x)
{
	printf("0x%08x",x);
}

