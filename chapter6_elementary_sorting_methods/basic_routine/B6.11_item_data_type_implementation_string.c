/*
** Item data type implementation for string items.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"item.h"

#define MAX_LENGTH 100

item_t rand_item(void)
{

}

/*
** Read the string from standard input, and dynamically
** allocate the storage to save it.
*/
int scan_item(item_t *px)
{
	int t;
	size_t len;

	*px=malloc(MAX_LENGTH*sizeof(**px));
	
	t=scanf("%s",*px);
	len=strlen(*px);
	*px=realloc(*px,len+1);

	return(t);
}

void print_item(item_t x)
{
	printf("%s",x);
}

int compare_item(item_t a,item_t b)
{
	return(strcmp(a,b));
}

void swap_item(item_t *pa,item_t *pb)
{
	item_t t;

	t=*pa;
	*pa=*pb;
	*pb=t;
}
