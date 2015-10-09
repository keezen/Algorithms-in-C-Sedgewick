#include<stdlib.h>
#include<math.h>
#include"complex.h"

struct complex{
	double radius;
	double theta;
};

complex_t complexInit(double re,double im)
{
	complex_t x=malloc(sizeof(*x));
	x->radius=sqrt(re*re+im*im);
	x->theta=atan2(im,re);
	return(x);
}

double Re(complex_t z)
{
	return(z->radius*cos(z->theta));
}

double Im(complex_t z)
{
	return(z->radius*sin(z->theta));
}

complex_t complexMult(complex_t x,complex_t y)
{
	complex_t t=malloc(sizeof(*t));
	t->radius=x->radius * y->radius;
	t->theta=x->theta + y->theta;
	return(t);
}
