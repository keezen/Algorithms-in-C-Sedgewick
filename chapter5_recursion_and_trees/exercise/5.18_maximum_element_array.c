#include<stdio.h>
#include<math.h>

#define Nmax 5

typedef int item_t;

item_t max(item_t array[],int head,int tail)
{
	int k,p,N=tail-head+1,mid;
	int i,x,y;

	if(head==tail)
		return(array[head]);

	p=(int)ceil(log(N)/log(2))-1;
	for(k=1,i=1;i<=p;i++)
		k*=2;

	mid=head+k-1;

	x=max(array,head,mid);
	y=max(array,mid+1,tail);
	if(x>y)
		return(x);
	return(y);
}

int main(void)
{
	item_t array[Nmax];
	int i;

	for(i=0;i<Nmax;i++)
		array[i]=i*2;

	printf("max:%d\n",max(array,0,Nmax-1));

	return(0);
}
