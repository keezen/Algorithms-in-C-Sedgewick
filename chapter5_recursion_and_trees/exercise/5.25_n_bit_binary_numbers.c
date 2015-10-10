#include<stdio.h>
#include<stdlib.h>

int **malloc2d(int r,int c)
{
	int **t,i;
	
	t=malloc(r*sizeof(int*));
	for(i=0;i<r;i++)
		t[i]=malloc(c*sizeof(int));

	return(t);
}

int main(int argc,char *argv[])
{
	int M,N=atoi(argv[1]);
	int i,j;
	int **array;

	for(M=1,i=0;i<N;i++)
		M*=2;
	array=malloc2d(M,N);

	for(i=0;i<M;i++){
		int t=i;

		for(j=0;j<N;j++){
			array[i][N-1-j]=t%2;
			t/=2;
		}
	}

	for(i=0;i<M;i++){
		for(j=0;j<N;j++)
			printf("%d ",array[i][j]);
		putchar('\n');
	}

	return(0);
}
