#include"matrix.h"

#define M 2
#define N 2

int main(void)
{
	matr_t m1,m2,m3,m4,m5;

	m1=matrixInit(M,N,0,0,1);
	matrixPrint(m1);
	putchar('\n');

	m2=matrixInit(M,N,1,1,1);
	matrixPrint(m2);
	putchar('\n');

	m3=matrixAdd(m1,m2);	
	matrixPrint(m3);
	putchar('\n');

	m4=matrixNumMult(m3,2);
	matrixPrint(m4);
	putchar('\n');

	m5=matrixMult(m3,m4);
	matrixPrint(m5);
	putchar('\n');

	return(0);
}
