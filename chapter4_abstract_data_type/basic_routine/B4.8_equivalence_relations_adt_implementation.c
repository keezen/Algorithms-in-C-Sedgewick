#include<stdlib.h>
#include"uf.h"

static int *array,*size;

void UFinit(int N)
{
	int i;
	array=malloc(N*sizeof(int));
	size=malloc(N*sizeof(int));
	for(i=0;i<N;i++){
		array[i]=i;
		size[i]=1;
	}
}

static int find(int x)
{
	int i;
	for(i=x;array[i]!=i;i=array[i])
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
	if(size[i]<size[j]){
		array[i]=j;
		size[j]+=size[i];
	}else{
		array[j]=i;
		size[i]+=size[j];
	}		
}
