#include<stdio.h>

int array[1000];
int ptr=0;

void shift(int N,int d)
{
	if(d>0){
		array[ptr++]=N;
		return;
	}

	if(d<0){
		array[ptr++]=-N;
		return;
	}
}

void hanoi(int N,int d)
{

	if(N==1){
		shift(N,d);
		return;
	}

	hanoi(N-1,-d);
	shift(N,d);
	hanoi(N-1,-d);
}

int main(int argc,char *argv[])
{
	int i,N=atoi(argv[1]);

	hanoi(N,1);

	for(i=0;i<ptr;i++){
		if(array[i]>0)
			printf("+%d ",array[i]);
		if(array[i]<0)
			printf("%d ",array[i]);		
	}
	putchar('\n');

	return(0);
}
