#include<stdio.h>
#include<stdlib.h>
#include"poly.h"

int main(int argc,char *argv[])
{
	int i,N=atoi(argv[1]);
	double x=atof(argv[2]);
	poly_t p,y;

	p=polyAdd(polyTerm(1,1),polyTerm(1,0));

	for(y=p,i=1;i<N;i++){
		y=polyMult(p,y);
	}

	puts("binomial coefficients:");
	polyShow(y);
	putchar('\n');
	putchar('\n');
	printf("(%.3f+1)^%d: %.3f\n",x,N,polyEval(y,x));

	return(0);
}
