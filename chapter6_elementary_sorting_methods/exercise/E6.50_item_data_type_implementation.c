/*
** Implementation for complex number item data type interface.
*/
#include<stdio.h>
#include<stdlib.h>
#include"item.h"

struct COMPLEX{
	double re;
	double im;
};

item_t rand_item(void)
{
	item_t c=malloc(sizeof(*c));
		
	c->re=1.0*rand()/RAND_MAX;
	c->im=1.0*rand()/RAND_MAX;

	return(c);
}

int scan_item(item_t *px)
{
	*px=malloc(sizeof(**px));

	return(scanf("%lf %lf",&((*px)->re),&((*px)->im)));
}

void print_item(item_t x)
{
	printf("%.2f+i%.2f",x->re,x->im);
}

int compare_item(item_t a,item_t b)
{
	double ma,mb;

	ma=(a->re)*(a->re)+(a->im)*(a->im);
	mb=(b->re)*(b->re)+(b->im)*(b->im);

	if(ma>mb){
		return(1);
	}

	if(ma==mb)
		return(0);

	if(ma<mb)
		return(-1);
}

void swap_item(item_t *pa,item_t *pb)
{
	item_t t;

	t=*pa;
	*pa=*pb;
	*pb=t;
}
