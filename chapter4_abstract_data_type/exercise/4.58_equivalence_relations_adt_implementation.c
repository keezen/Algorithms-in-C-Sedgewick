#include<stdlib.h>
#include<stdio.h>
#include"uf.h"

struct uf{
	int *array;
	int *size;
	int N;
};

uf_t UFinit(int Nmax)
{
	int i;
	uf_t x=malloc(sizeof(*x));
	x->array=malloc(Nmax*sizeof(int));
	x->size=malloc(Nmax*sizeof(int));
	x->N=Nmax;
	for(i=0;i<Nmax;i++){
		x->array[i]=i;
		x->size[i]=1;
	}

	return(x);
}

static int find(uf_t uf,int x)
{
	int i;
	for(i=x;uf->array[i] != i;i = uf->array[i])
		;
	return(i);
}

int UFfind(uf_t uf,int p,int q)
{
	return(find(uf,p) == find(uf,q));
}

void UFunion(uf_t uf,int p,int q)
{
	int i,j;
	if((i=find(uf,p)) == (j=find(uf,q)))
		return;
	if(uf->size[i] < uf->size[j]){
		uf->array[i]=j;
		uf->size[j]+=uf->size[i];
	}else{
		uf->array[j]=i;
		uf->size[i]+=uf->size[j];
	}		
}

void UFdump(uf_t uf)
{
	int i;
	for(i=0;i < uf->N;i++)
		printf("%d ",i);
	putchar('\n');
	for(i=0;i < uf->N;i++)
		printf("%d ",uf->array[i]);		
}
