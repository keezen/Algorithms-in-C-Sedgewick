#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int item_t;

int compare(void *a,void *b);
void swap(void *a,void *b);
void insertion_sort(item_t *array,int left,int right);
void print_array(item_t *array,int n_elements);

int compare(void *a,void *b)
{
	return(*(int *)a - *(int *)b);
}

void swap(void *a,void *b)
{
	int t;

	t=*(int *)a;
	*(int *)a=*(int *)b;
	*(int *)b=t;
}

void insertion_sort(item_t *array,int left,int right)
{
	int i,j;
	item_t temp;

	for(i=left+1;i<=right;i++)
		if(compare(&array[i],&array[left]) < 0)
			swap(&array[i],&array[left]);

	for(i=left+2;i<=right;i++){
		temp=array[i];

		for(j=i-1;compare(&array[j],&temp) > 0;j--){
			array[j+1]=array[j];
		}

		array[j+1]=temp;
	} 
}

void print_array(item_t *array,int n_elements)
{
	int i;

	for(i=0;i<n_elements;i++)
		printf("%2d ",array[i]);
	putchar('\n');
}

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	item_t *array=malloc(N*sizeof(*array));
	int i;
	
	srand((unsigned)time(NULL));

	for(i=0;i<N;i++){
		array[i]=rand()%100;
	}

	print_array(array,N);

	insertion_sort(array,0,N-1);

	print_array(array,N);

	return(0);
}
