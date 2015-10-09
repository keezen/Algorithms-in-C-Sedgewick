#include<stdio.h>
#include<math.h>
#include"complex.h"

int main(int argc,char *argv[])
{
	int k,i,N=atoi(argv[1]);
	double theta;
	complex_t x,y;

	for(k=0;k<N;k++){
		printf("%2d\t",k);

		theta=2.0*M_PI*k/N;
		x=complexInit(cos(theta),sin(theta));
		printf("%6.3f %6.3f\t",Re(x),Im(x));

		for(y=x,i=1;i<=N-1;i++)
			y=complexMult(x,y);
		printf("%6.3f %6.3f\t",Re(y),Im(y));

		putchar('\n');
	}

	return(0);
}
