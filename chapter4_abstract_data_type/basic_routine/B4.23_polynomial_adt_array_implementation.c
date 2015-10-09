#include<stdlib.h>
#include<stdio.h>
#include"poly.h"

struct poly{
	int degr;
	int *coef;
};

poly_t polyTerm(int coef,int exp)
{
	poly_t p=malloc(sizeof(*p));
	int i;

	p->degr=exp+1;
	p->coef=malloc((exp+1)*sizeof(int));
	
	p->coef[exp]=coef;
	for(i=0;i<exp;i++)
		p->coef[i]=0;

	return(p);	
}

poly_t polyAdd(poly_t p1,poly_t p2)
{
	poly_t t;
	int i;

	if(p1->degr < p2->degr){
		t=p1;
		p1=p2;
		p2=t;
	}

	for(i=0;i < p2->degr;i++)
		p1->coef[i] += p2->coef[i];

	return(p1);
}

poly_t polyMult(poly_t p1,poly_t p2)
{
	poly_t p;
	int i,j;
	int exp = p1->degr + p2->degr - 2;

	p=polyTerm(0,exp);
	for(i=0;i < p1->degr;i++)
		for(j=0;j < p2->degr;j++)
			p->coef[i+j] += p1->coef[i] * p2->coef[j];

	return(p);
}

double polyEval(poly_t p,double x)
{
	double y;
	int i;
	int exp = p->degr - 1;

	for(y=p->coef[exp],i=exp-1;i>=0;i--)
		y= y*x + p->coef[i];

	return(y);
}

void polyShow(poly_t p)
{
	int i;
	for(i=0;i < p->degr;i++)
		printf("%d ",p->coef[i]);
}
