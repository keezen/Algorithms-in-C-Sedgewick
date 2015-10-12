#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

#define SIZE_1 10
#define SIZE_2 100
#define SIZE_3 1000

int total_comp;
int size_1_comp;
int size_2_comp;
int size_3_comp;

int partition(item_t *array,int left,int right);
void quick_sort(item_t *array,int left,int right);
void print_array(item_t *array,int n_elements);

int partition(item_t *array,int left,int right)
{
	item_t v=array[right];
	int i,j;
	int last_total=total_comp;

	i=left-1;
	j=right;
	while(1){
		while((total_comp++,compare_item(array[++i],v))<0)
			;
		while((total_comp++,compare_item(array[--j],v))>0){
			if(j==left)
				break;
		}
		if(i>=j)
			break;
		
		swap_item(&array[i],&array[j]);
	}

	swap_item(&array[i],&array[right]);

	if(right-left+1<SIZE_3){
		size_3_comp+=total_comp-last_total;
		if(right-left+1<SIZE_2){
			size_2_comp+=total_comp-last_total;
			if(right-left+1<SIZE_1){
				size_1_comp+=total_comp-last_total;
			}
		}
	}

	return(i);
}

void quick_sort(item_t *array,int left,int right)
{
	int i;

	if(right-left+1 <= 1){
		return;
	}

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
	int N=atoi(argv[1]);
	item_t *array=malloc(N*sizeof(*array));
	int i;

	srand((unsigned)time(NULL));

	for(i=0;i<N;i++){
		array[i]=rand()%N;
	}

	total_comp=0;
	size_1_comp=0;
	size_2_comp=0;
	size_3_comp=0;
	quick_sort(array,0,N-1);
	printf("total comparison: %d\n",total_comp);
	printf("less than %d comparison: %.1f%%\n",SIZE_1,(double)size_1_comp/total_comp*100.0);
	printf("less than %d comparison: %.1f%%\n",SIZE_2,(double)size_2_comp/total_comp*100.0);
	printf("less than %d comparison: %.1f%%\n",SIZE_3,(double)size_3_comp/total_comp*100.0);

	return(0);
}
