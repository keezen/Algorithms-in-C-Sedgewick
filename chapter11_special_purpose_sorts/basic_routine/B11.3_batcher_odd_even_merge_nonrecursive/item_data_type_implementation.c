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

int compare_item(item_t *a,item_t *b)
{
	return(*a-*b);
}

void compare_swap_item(item_t *a,item_t *b)
{
	if(compare_item(a,b)>0){
		swap_item(a,b);
	}
}

void print_item(item_t *x)
{
	printf("%d",*x);
}

