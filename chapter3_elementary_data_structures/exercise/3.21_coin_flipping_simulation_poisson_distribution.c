#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int heads(int N,double lambda)
{
	return(rand()<RAND_MAX*lambda/N);
}

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]),M=atoi(argv[2]);
	int i,j,*count,result;
	double lambda=8;

	count=malloc((N+1)*sizeof(int));
	srand((unsigned)time(NULL));

	for(i=1;i<=M;i++){
		result=0;

		for(j=1;j<=N;j++)
			if(heads(N,lambda))
				result++;

		count[result]++;
	}

	for(i=0;i<=N;i++){
		printf("%2d: ",i);
		for(j=0;j<count[i];j+=10)
			putchar('*');
		putchar('\n');
	}	

	return(0);
}
