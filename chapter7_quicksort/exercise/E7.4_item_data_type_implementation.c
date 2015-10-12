#include<stdio.h>
#include<string.h>
#include"item.h"

extern int compare_number;

void copy_item(item_t *a,item_t *b)
{
	*a=*b;
}

void print_item(item_t x)
{
	printf("(%s,%d)",x.name,x.number);
}

static int compare_item_number(item_t a,item_t b)
{
	return(a.number-b.number);
}

static int compare_item_name(item_t a,item_t b)
{
	return(strcmp(a.name,b.name));
}

int compare_item(item_t a,item_t b)
{
	if(compare_number==0)
		compare_item_name(a,b);
	else
		compare_item_number(a,b);
}
