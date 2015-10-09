#include<stdio.h>
#include<time.h>
#include"queue.h"

#define M 10

int main(int argc,char *argv[])
{
	int i,j,N=atoi(argv[1]);
	queue_t queues[M];
	
	srand((unsigned)time(NULL));
	for(i=0;i<M;i++)
		queues[i]=queueInit(N);

	for(i=0;i<N;i++)
		queuePut(queues[rand()%M],i);
		
	for(i=0;i<M;i++){
		printf("queues[%d]: ",i);
		while(!queueEmpty(queues[i]))
			printf("%3d ",queueGet(queues[i]));
		putchar('\n');
	}

	return(0);
}
