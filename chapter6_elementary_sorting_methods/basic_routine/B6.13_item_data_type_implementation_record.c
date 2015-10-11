/*
** The implementation for record items data type.
** The records have two keys: a string key in the first
** field, and an integer key in the second field.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"item.h"

/*
** If the macro COMPARE equals 0, it means the key to be
** compared is the integer key, otherwise the key is the
** string "name".
*/
#define COMPARE 1

struct RECORD{
	char name[30];
	int num;
};

item_t rand_item(void)
{

}

int scan_item(item_t *px)
{
	*px=malloc(sizeof(**px));

	return(scanf("%s %d",(*px)->name,&((*px)->num)));
}

void print_item(item_t x)
{
	putchar('(');
	printf("%s,%d",x->name,x->num);
	putchar(')');
}

#if COMPARE==0

int compare_item(item_t a,item_t b)
{
	return(a->num - b->num);
}

#else

int compare_item(item_t a,item_t b)
{
	return(strcmp(a->name,b->name));
}

#endif

void swap_item(item_t *pa,item_t *pb)
{
	item_t t;

	t=*pa;
	*pa=*pb;
	*pb=t;
}
