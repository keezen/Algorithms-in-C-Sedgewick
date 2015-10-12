#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

#define MODIFIED 0

int partition(item_t *array,int left,int right);
void quick_sort(item_t *array,int left,int right);
void print_array(item_t *array,int n_elements);

int partition(item_t *array,int left,int right)
{
	item_t v=array[right];
	int i,j;

	i=left-1;
	j=right;
	while(1){
		while(compare_item(array[++i],v)<0)
			;
		while(compare_item(array[--j],v)>0){
			if(j==left)
				break;
		}
		if(i>=j)
			break;
		
		swap_item(&array[i],&array[j]);
	}

	swap_item(&array[i],&array[right]);

	return(i);
}

void quick_sort(item_t *array,int left,int right)
{
	int i;
	item_t v;

	if(right-left+1 <= 1){
		return;
	}
	
	/*
	** If all keys in the subfile are equal, function will return.
	*/
	#if MODIFIED==1
		for(v=array[right],i=left;i<right && compare_item(array[i],v)==0;i++)
			;
		if(i==right){
			return;
		}
	#endif

	i=partition(array,left,right);
	quick_sort(array,left,i-1);
	quick_sort(array,i+1,right);
}

void print_array(item_t *array,int n_elements)
{
	int i;

	for(i=0;i<n_elements;i++){
		print_item(array[i]);
		putchar(' ');
	}
	putchar('\n');
}

int main(int argc,char *argv[])
{
	int N=atoi(argv[2]);
	int t=atoi(argv[1]);
	item_t *array=malloc(N*sizeof(*array));
	int i;
	clock_t c1,c2;

	srand((unsigned)time(NULL));

	for(i=0;i<N;i++){
		array[i]=rand()%t;
	}

	c1=clock();
	quick_sort(array,0,N-1);
	c2=clock();
	printf("sorted time: %.5fs\n",(double)(c2-c1)/CLOCKS_PER_SEC);

	return(0);
}
