#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

int partition(item_t *array,int left,int right);
void selection(item_t *array,int left,int right,int k);
void print_array(item_t *array,int n_elements);

int count_comp;

int partition(item_t *array,int left,int right)
{
	item_t v=array[right];
	int i,j;

	i=left-1;
	j=right;
	while(1){
		while((count_comp++,compare_item(array[++i],v))<0)
			;
		while((count_comp++,compare_item(array[--j],v))>0){
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

void selection(item_t *array,int left,int right,int k)
{
	int i;	

	if(right-left+1<=1){
		return;
	}

	i=partition(array,left,right);
	if(i==k){
		return;
	}
	if(i>k){
		selection(array,left,i-1,k);
	}
	if(i<k){
		selection(array,i+1,right,k);
	}
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
	/*
	** It is better to input N as an odd.
	*/
	int N=atoi(argv[1]);
	item_t *array=malloc(N*sizeof(*array));
	int i;
	int k=(N-1)/2;

	srand((unsigned)time(NULL));

	/*
	** Construct the worse case to find the median
	** of N elements.
	*/
	for(i=0;i<N;i++){
		if(i<k)
			array[i]=i+2;
		if(i==k)
			array[i]=1;
		if(i>k)
			array[i]=i+1;
	}
//	print_array(array,N);

	count_comp=0;
	selection(array,0,N-1,k);
//	print_array(array,N);
	printf("the %dth smallest item is %d.\n",k+1,array[k]);
	printf("number of comparisons: %d\n",count_comp);

	free(array);

	return(0);
}
