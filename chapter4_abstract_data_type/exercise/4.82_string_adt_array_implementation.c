#include<stdlib.h>
#include<stdio.h>
#include"string.h"

struct string{
	char *array;
};

str_t stringCrea(int N,char *sour)
{
	str_t dest=malloc(sizeof(*dest));
	int i;

	dest->array=malloc((N+1)*sizeof(char));
	for(i=0;sour[i]!=0;i++)
		dest->array[i]=sour[i];
	dest->array[i]=0;

	return(dest);
}

int stringLeng(str_t s)
{
	int i;
	for(i=0;s->array[i]!=0;i++)
		;
	return(i);
}

int stringComp(str_t s1,str_t s2)
{
	int i;

	for(i=0;s1->array[i]==s2->array[i] && s1->array[i]!=0 && s2->array[i]!=0;i++)
		;

	if(s1->array[i]==0 || s2->array[i]==0)
		return(0);

	if(s1->array[i] - s2->array[i] > 0)
		return(1);
	if(s1->array[i] - s2->array[i] < 0)
		return(-1);
}

str_t stringConcat(str_t dest,str_t sour)
{
	int i,begin=stringLeng(dest);

	for(i=0;sour->array[i] != 0;i++)
		dest->array[begin+i] = sour->array[i];
	dest->array[begin+i]=0;
	
	return(dest);
}

str_t stringCopy(str_t dest,str_t sour)
{
	int i;

	for(i=0;sour->array[i] != 0;i++)
		dest->array[i]=sour->array[i];
	dest->array[i]=0;

	return(dest);
}

void stringPrint(str_t s)
{
	int i;

	for(i=0;s->array[i] != 0;i++)
		putchar(s->array[i]);
}
