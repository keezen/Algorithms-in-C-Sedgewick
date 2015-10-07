#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]),M=atoi(argv[2]);
	int *array,i,x;

	array=malloc((N+1)*sizeof(int));	

	for(i=1;i<=N-1;i++){
		array[i]=i+1;
	}
	array[N]=1;

	printf("quit order:");

	x=N;
	while(array[x]!=x){
		for(i=1;i<M;x=array[x],i++);
		
		printf("%d ",array[x]);
	
		array[x]=array[array[x]];
	}

	putchar('\n');
	printf("the target:%d\n",x);

	free(array);

	return(0);
}
