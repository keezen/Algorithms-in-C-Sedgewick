#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int heads(void)
{
	return(rand()<RAND_MAX/6);
}

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]),M=atoi(argv[2]);
	int i,j,*count,result;

	count=malloc((N+1)*sizeof(int));
	srand((unsigned)time(NULL));

	for(i=1;i<=M;i++){
		result=0;

		for(j=1;j<=N;j++)
			if(heads())
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
