#include<stdlib.h>
#include<stdio.h>
#include"vector.h"
	
struct vector{
	int N;
	item_t *array;
};

vector_t vectorInit(int N,int index,item_t item)
{
	vector_t v=malloc(sizeof(*v));
	int i;

	v->N = N;
	v->array = malloc(N*sizeof(item_t));
	v->array[index]=item;
	
	for(i=0;i<N;i++)
		if(i!=index)
			v->array[i]=0;

	return(v);
}

static void vectorError(void)
{
	puts("Illegal Operation!");
}

vector_t vectorAdd(vector_t v1,vector_t v2)
{	
	vector_t v;
	int i;

	if(v1->N != v2->N){
		vectorError();
		return;
	}

	v=vectorInit(v1->N,0,0);
	
	for(i=0;i < v1->N;i++)
		v->array[i] = v1->array[i] + v2->array[i];

	return(v);
}

item_t vectorMult(vector_t v1,vector_t v2)
{
	item_t pro;
	int i;

	if(v1->N != v2->N){
		vectorError();
		return;
	}
	
	for(pro=0,i=0;i < v1->N;i++)
		pro += v1->array[i] * v2->array[i];

	return(pro);
}

void vectorPrint(vector_t v)
{
	int i;
	
	for(i=0;i < v->N;i++)
		printf("%.2f ",v->array[i]);
}
