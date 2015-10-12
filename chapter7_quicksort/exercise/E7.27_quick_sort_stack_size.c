#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

int partition(item_t *array,int left,int right);
void insertion_sort(item_t *array,int left,int right);
void quick_sort(item_t *array,int left,int right);
void print_array(item_t *array,int n_elements);

int M;
int count,max;

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

void insertion_sort(item_t *array,int left,int right)
{
	int i,j;
	item_t temp;

	for(i=left+1;i<=right;i++)
		if(compare_item(array[i],array[left]) < 0)
			swap_item(&array[i],&array[left]);

	for(i=left+2;i<=right;i++){
		temp=array[i];

		for(j=i-1;compare_item(array[j],temp) > 0;j--){
			array[j+1]=array[j];
		}

		array[j+1]=temp;
	} 
}

void quick_sort(item_t *array,int left,int right)
{
	int i;
	
	count++;
	if(count>max){
		max=count;
	}

	if(right-left+1 <= M){
		insertion_sort(array,left,right);

		count--;
		return;
	}

	i=partition(array,left,right);
	quick_sort(array,left,i-1);
	quick_sort(array,i+1,right);

	count--;
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
	item_t *array=malloc(N*sizeof(*array));
	int i;

	M=atoi(argv[1]);
	srand((unsigned)time(NULL));

	for(i=0;i<N;i++){
		array[i]=rand()%N;
	}

	count=0;
	max=0;
	quick_sort(array,0,N-1);

	printf("count: %d\n",count);
	printf("stack size: %d\n",max);

	free(array);

	return(0);
}
