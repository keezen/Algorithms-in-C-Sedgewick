/*
** Implemention of the first-class item ADT.
*/
#include<stdio.h>
#include<stdlib.h>
#include"item.h"

struct ITEM{
	double f;
};

item_t rand_item(void)
{
	item_t new=malloc(sizeof(*new));

	new->f=1.0*rand()/RAND_MAX;

	return(new);
}

int scan_item(item_t *px)
{
	*px=malloc(sizeof(**px));

	return(scanf("%lf",&((*px)->f)));
}

void print_item(item_t x)
{
	printf("%.2f",x->f);
}

int compare_item(item_t a,item_t b)
{
	double key_a,key_b;

	key_a=a->f;
	key_b=b->f;

	if(key_a>key_b)
		return(1);

	if(key_a==key_b)
		return(0);

	if(key_a<key_b)
		return(-1);
}

void swap_item(item_t *pa,item_t *pb)
{
	item_t t;

	t=*pa;
	*pa=*pb;
	*pb=t;
}
