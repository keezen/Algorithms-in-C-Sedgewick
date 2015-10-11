#include<stdio.h>
#include"item.h"

int key_item(item_t x)
{
	return(x.number);
}

void copy_item(item_t *a,item_t *b)
{
	*a=*b;
}

void print_item(item_t x)
{
	printf("(%c,%d)",x.ch,x.number);
}

