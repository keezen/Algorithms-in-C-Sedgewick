#include<stdio.h>
#include"item.h"

void copy_item(item_t *a,item_t *b)
{
	*a=*b;
}

void print_item(item_t x)
{
	printf("%d",x);
}

int compare_item(item_t a,item_t b)
{
	return(a-b);
}
