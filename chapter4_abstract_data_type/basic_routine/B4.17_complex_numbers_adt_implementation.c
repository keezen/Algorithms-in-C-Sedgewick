#include<stdlib.h>
#include"complex.h"

struct complex{
	double re;
	double im;
};

complex_t complexInit(double re,double im)
{
	complex_t x=malloc(sizeof(*x));
	x->re=re;
	x->im=im;
	return(x);
}

double Re(complex_t z)
{
	return(z->re);
}

double Im(complex_t z)
{
	return(z->im);
}

complex_t complexMult(complex_t x,complex_t y)
{
	complex_t t=malloc(sizeof(*t));
	t->re=x->re*y->re - x->im*y->im;
	t->im=x->re*y->im + x->im*y->re;
	return(t);
}
