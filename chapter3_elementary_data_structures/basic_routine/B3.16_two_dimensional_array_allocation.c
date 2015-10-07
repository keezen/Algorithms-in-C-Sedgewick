#include<stdio.h>
#include<stdlib.h>

#define M 10
#define N 8

int **malloc2d(int r,int c)
{
	int **t,i;
	
	t=malloc(r*sizeof(int*));
	for(i=0;i<r;i++)
		t[i]=malloc(c*sizeof(int));

	return(t);
}

int main(void)
{
	int **array2d,i,j;

	array2d=malloc2d(M,N);

	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
			array2d[i][j]=i+j;

	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
			printf("array2d[%d][%d]:%d\n",i,j,array2d[i][j]);

	return(0);
}
