#include<stdio.h>

int N;
int k;

typedef int item_t;

item_t max(item_t array[],int head,int tail)
{
	int len=tail-head+1;
	int i,s,r;
	item_t t,maxv;
	int size[k],node[2*k];

	printf("max(%d,%d)\n",head,tail);

	if(head==tail)
		return(array[head]);

	s=len/k;
	r=len%k;

	for(node[0]=head,i=0;i<k;i++){
		if(i<r)
			size[i]=s+1;
		else
			size[i]=s;

		if(i==0)
			node[2*i+1]=node[2*i]+size[i]-1;
		else{
			node[2*i]=node[2*i-2]+size[i-1];
			node[2*i+1]=node[2*i]+size[i]-1;
		}		
	}

	for(maxv=0,i=0;i<k;i++)
		if(node[2*i]<=node[2*i+1])
			if((t=max(array,node[2*i],node[2*i+1])) > maxv)
				maxv=t;

	return(maxv);
}

int main(int argc,char *argv[])
{
	N=atoi(argv[1]);
	k=atoi(argv[2]);

	item_t array[N];
	int i,s,r;
	
	for(i=0;i<N;i++)
		array[i]=i*2;

	printf("max:%d\n",max(array,0,N-1));

	return(0);
}
