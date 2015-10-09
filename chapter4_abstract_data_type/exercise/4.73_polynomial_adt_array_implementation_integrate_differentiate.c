#include<stdlib.h>
#include<stdio.h>
#include"poly.h"

struct poly{
	int degr;
	double *coef;
};

poly_t polyTerm(double coef,int exp)
{
	poly_t p=malloc(sizeof(*p));
	int i;

	p->degr=exp+1;
	p->coef=malloc((exp+1)*sizeof(double));
	
	p->coef[exp]=coef;
	for(i=0;i<exp;i++)
		p->coef[i]=0;

	return(p);	
}

poly_t polyAdd(poly_t p1,poly_t p2)
{
	poly_t p;
	int i,exp = (p1->degr > p2->degr)?(p1->degr - 1):(p2->degr - 1);;

	p=polyTerm(0,exp); 

	for(i=0;i < p->degr;i++)
		p->coef[i] = p1->coef[i] + p2->coef[i];

	polyDestroy(p1);
	polyDestroy(p2);

	return(p);
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

	polyDestroy(p1);
	polyDestroy(p2);

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
		printf("%.2f*x^%d ",p->coef[i],i);
}

void polyDestroy(poly_t p)
{
	free(p->coef);
	free(p);
}

poly_t polyCopy(poly_t sour)
{
	int i,exp = sour->degr - 1;
	poly_t dest=polyTerm(0,exp);

	for(i=0;i<=exp;i++)
		dest->coef[i] = sour->coef[i];

	return(dest);
}

poly_t polyInte(poly_t sour)
{
	int i,exp = sour->degr - 1; 
	poly_t dest=polyTerm(0,exp+1);

	dest->coef[0]=0;
	for(i=1;i < dest->degr;i++)
		dest->coef[i] = sour->coef[i-1] / i;

	return(dest); 
}

poly_t polyDiff(poly_t sour)
{
	int i,exp = sour->degr - 1;
	poly_t dest=polyTerm(0,exp-1);

	for(i=0;i < dest->degr;i++)
		dest->coef[i] = sour->coef[i+1] * (i+1);

	return(dest);
}
