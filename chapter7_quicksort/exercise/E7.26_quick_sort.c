#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

#define M 10

int partition(item_t *array,int left,int right);
void insertion_sort(item_t *array,int left,int right);
void quick_sort(item_t *array,int left,int right);
void print_array(item_t *array,int n_elements);

int count_sub[M+1];

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

	if(right-left+1 <= M){
		count_sub[right-left+1]++;
		insertion_sort(array,left,right);
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
	int i,j;
	int step;

	srand((unsigned)time(NULL));

	for(i=0;i<=M;i++){
		count_sub[i]=0;
	}

	for(i=0;i<N;i++){
		array[i]=rand()%N;
	}

	quick_sort(array,0,N-1);

	printf("subfile size for insertion:\n");
	print_array(count_sub,M+1);
	putchar('\n');

	for(i=0;i<=M;i++){
		printf("%2d:\t",i);
		step=N/1000;
		step=(step==0)?1:step;
		for(j=0;j<count_sub[i];j+=step){
			printf("*");		
		}
		putchar('\n');		
	}

	free(array);

	return(0);
}
