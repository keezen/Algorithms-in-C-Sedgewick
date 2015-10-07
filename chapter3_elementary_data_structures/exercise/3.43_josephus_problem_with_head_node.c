#include<stdio.h>
#include"list.h"

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]),M=atoi(argv[2]);
	int i;
	node_t x,t,head;

	initNodes(N+1);

	head=newNode(0);
	for(x=head,i=1;i<=N;i++){
		t=newNode(i);
		insertNext(x,t);
		x=t;
	}

	printf("quit order:");

	while(Next(Next(x))!=x){
		i=1;
		while(i<M){
			x=Next(x);
			if(x!=head)
				i++;	
		}
	
		if(Next(x)!=head){
			printf("%d ",Item(Next(x)));
			freeNode(deleteNext(x));
		}
		else{
			printf("%d ",Item(Next(head)));
			freeNode(deleteNext(head));
		}
	}

	putchar('\n');
	printf("the target:%d\n",Item(x));

	return(0);
}
