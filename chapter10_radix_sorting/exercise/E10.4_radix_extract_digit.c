#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"radix.h"
#include"item_radix.h"

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	item_t *array=malloc(N*sizeof(*array));
	int i;
	clock_t c1,c2;

	srand((unsigned)time(NULL));

	for(i=0;i<N;i++){
		array[i]=rand()%N;
	}

	c1=clock();
	for(i=0;i<N;i++){
		digit(array[i],rand()%32);
	}
	c2=clock();
	printf("extract time: %.5fs\n",(double)(c2-c1)/CLOCKS_PER_SEC);

	return(0);
}
