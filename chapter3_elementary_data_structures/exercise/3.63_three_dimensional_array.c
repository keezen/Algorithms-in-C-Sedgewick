#include<stdio.h>
#include<stdlib.h>

#define X 3
#define Y 2
#define Z 1

int **malloc2d(int r,int c)
{
	int **t,i;
	
	t=malloc(r*sizeof(int*));
	for(i=0;i<r;i++)
		t[i]=malloc(c*sizeof(int));

	return(t);
}

int ***malloc3d(int x,int y,int z)
{
	int ***t,i;

	t=malloc(x*sizeof(int**));
	for(i=0;i<x;i++)
		t[i]=malloc2d(y,z);

	return(t);
}

int main(void)
{
	int ***array3d,i,j,k;

	array3d=malloc3d(X,Y,Z);

	for(i=0;i<X;i++)
		for(j=0;j<Y;j++)
			for(k=0;k<Z;k++)
				array3d[i][j][k]=i+j+k;

	for(i=0;i<X;i++)
		for(j=0;j<Y;j++)
			for(k=0;k<Z;k++)
				printf("array3d[%d][%d][%d]:%d\n",i,j,k,array3d[i][j][k]);

	return(0);
}
