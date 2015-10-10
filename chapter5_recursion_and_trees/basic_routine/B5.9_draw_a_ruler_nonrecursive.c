#include<stdio.h>
#include<stdlib.h>

int *array;

void mark(int index,int height)
{
	array[index]=height;
}

void rule(int head,int tail,int height)
{
	int i,j,step;

	for(step=2,i=1;i<=height;step*=2,i++){
		for(j=head+step/2;j<=tail;j+=step)
			mark(j,i);
	}
}

int main(int argc,char *argv[])
{
	int i,height=atoi(argv[1]);
	int head,tail,len;
	
	for(len=1,i=1;i<=height;i++)
		len*=2;
	head=0;
	tail=head+len;

	array=malloc((tail+1)*sizeof(int));
	for(i=head;i<=tail;i++)
		array[i]=0;

	rule(head,tail,height);

	for(i=head;i<=tail;i++)
		printf("%d ",i);
	putchar('\n');
	for(i=head;i<=tail;i++)
		printf("%d ",array[i]);
	putchar('\n');

	return(0);
}
