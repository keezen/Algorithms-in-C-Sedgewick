#include<stdio.h>
#include<string.h>
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
	return(strcmp(a,b));
}

void print_item(item_t x)
{
	printf("%s",x);
}

