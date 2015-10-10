#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *array;

void mark(int index,int height)
{
	array[index]=height;
}

void rule(int head,int tail,int height)
{
	int mid=(head+tail)/2;

	if(height==0)
		return;

	mark(mid,height);
	rule(head,mid,height-1);
	rule(mid,tail,height-1);
}

int length(int head,int tail,int height,int index)
{
	int mid=(head+tail)/2;

	if(index==mid)
		return(height);

	if(index<mid)
		return(length(head,mid,height-1,index));
	if(index>mid)
		return(length(mid,tail,height-1,index));
}

int main(int argc,char *argv[])
{
	int i,height=atoi(argv[1]);
	int head,tail,len,index;
	
	srand((unsigned)time(NULL));

	for(len=1,i=1;i<=height;i++)
		len*=2;
	head=0;
	tail=head+len;

	array=malloc((tail+1)*sizeof(int));
	for(i=head;i<=tail;i++)
		array[i]=0;

	rule(head,tail,height);

	for(i=head;i<=tail;i++)
		printf("%2d ",i);
	putchar('\n');
	for(i=head;i<=tail;i++)
		printf("%2d ",array[i]);
	putchar('\n');

	index=rand()%(len-1)+head+1;
	printf("index:%d\n",index);
	printf("length of %dth mark:%d\n",index,length(head,tail,height,index));

	return(0);
}
