#include<stdlib.h>
#include"uf.h"

typedef struct{
	int next;
	int size;
} node_t;

static node_t *array;

void UFinit(int N)
{
	int i;
	array=malloc(N*sizeof(node_t));
	for(i=0;i<N;i++){
		array[i].next=i;
		array[i].size=1;
	}
}

static int find(int x)
{
	int i;
	for(i=x;array[i].next!=i;i=array[i].next)
		;
	return(i);
}

int UFfind(int p,int q)
{
	return(find(p)==find(q));
}

void UFunion(int p,int q)
{
	int i,j;
	if((i=find(p))==(j=find(q)))
		return;
	if(array[i].size<array[j].size){
		array[i].next=j;
		array[j].size+=array[i].size;
	}else{
		array[j].next=i;
		array[i].size+=array[j].size;
	}		
}
