#include<stdlib.h>
#include<stdio.h>
#include"set.h"

struct set{
	int M;
	int *array;
};

set_t setCrea(int M)
{
	set_t s=malloc(sizeof(*s));
	int i;

	s->M=M;
	s->array=malloc(M*sizeof(int));

	for(i=0;i<M;i++)
		s->array[i]=0;	

	return(s);
}

static void setError(void)
{
	puts("Illegal Operation!");
}

void setInsert(set_t s,int index)
{
	if(index >= s->M){
		setError();
		return;
	}
	
	s->array[index]=1;
}

set_t setUnion(set_t s1,set_t s2)
{
	set_t s=setCrea(s1->M);
	int i;

	for(i=0;i < s->M;i++)
		if(s1->array[i]==1 || s2->array[i]==1)
			s->array[i]=1;

	return(s);
}

set_t setInter(set_t s1,set_t s2)
{
	set_t s=setCrea(s1->M);;
	int i;

	for(i=0;i < s->M;i++)
		if(s1->array[i]==1 && s2->array[i]==1)
			s->array[i]=1;	

	return(s);
}

set_t setCompl(set_t sour)
{
	set_t dest=setCrea(sour->M);
	int i;

	for(i=0;i < dest->M;i++)
		dest->array[i] = (sour->array[i] != 1);

	return(dest);
}

set_t setDiff(set_t s1,set_t s2)
{
	set_t s=setCrea(s1->M);;
	int i;

	for(i=0;i < s->M;i++)
		if(s1->array[i] + s2->array[i] == 1)
			s->array[i]=1;	

	return(s);
}

void setPrint(set_t s)
{
	int i;

	for(i=0;i < s->M;i++)
		if(s->array[i])
			printf("%d ",i);
}
