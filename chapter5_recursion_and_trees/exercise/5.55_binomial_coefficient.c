#include<stdio.h>
#include<stdlib.h>

#define UNKNOWN -1

int **knownBino;

int binomial(int N,int k)
{
	if(knownBino[N][k]!=UNKNOWN)
		return(knownBino[N][k]);
	
	if(k==0 || N==k)
		return(knownBino[N][k]=1);

	return(knownBino[N][k]=binomial(N-1,k)+binomial(N-1,k-1));
}

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
	int N=atoi(argv[1]);
	int k=atoi(argv[2]);
	int i,j;

	knownBino=malloc2d(N+1,k+1);
	for(i=0;i<=N;i++)
		for(j=0;j<=k;j++)
			knownBino[i][j]=UNKNOWN;

	printf("binomial(%d,%d):%d\n",N,k,binomial(N,k));

	return(0);
}
