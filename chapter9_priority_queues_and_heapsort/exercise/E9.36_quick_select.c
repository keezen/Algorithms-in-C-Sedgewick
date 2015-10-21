#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

int partition(item_t *array,int left,int right);
item_t quick_select(item_t *array,int left,int right,int k);
void print_array(item_t *array,int n_elements);

int count_comp=0;

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

/*
** This quick_select function selects the kth largest item in
** the array.
*/
item_t quick_select(item_t *array,int left,int right,int k)
{
	int i;
	int j=right-k+1;

	if(right-left+1<=1){
		return(array[left]);
	}

	i=partition(array,left,right);
	if(i==j){
		return(array[i]);
	}
	if(i>j){
		return(quick_select(array,left,i-1,i-j));
	}
	if(i<j){
		return(quick_select(array,i+1,right,right-j+1));
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
	int N=1000000;
	int k=atoi(argv[1]);
	item_t *array=malloc(N*sizeof(*array));
	int i;

	srand((unsigned)time(NULL));

	for(i=0;i<N;i++){
		array[i]=rand()%N;
	}
//	print_array(array,N);

	printf("the %dth largest item: %d\n",k,quick_select(array,0,N-1,k));
	printf("number of comparisons: %d\n",count_comp);
//	print_array(array,N);

	free(array);

	return(0);
}
