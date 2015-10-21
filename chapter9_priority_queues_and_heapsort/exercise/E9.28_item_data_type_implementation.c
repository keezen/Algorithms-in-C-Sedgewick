#include<stdio.h>
#include<string.h>
#include"item.h"

#define COMPARE_NUM 1

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
	#if COMPARE_NUM

	return(a.num-b.num);

	#else

	return(strcmp(a.name,b.name));

	#endif
}

void print_item(item_t x)
{
	printf("(%s,%d)",x.name,x.num);
}

