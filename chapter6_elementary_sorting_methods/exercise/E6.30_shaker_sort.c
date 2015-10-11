#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int item_t;

int compare(void *a,void *b);
void swap(void *a,void *b);
void shaker_sort(item_t *array,int left,int right);
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

void shaker_sort(item_t *array,int left,int right)
{
	int i,j,k;

	for(i=left,j=right;i<j;i++,j--){
		for(k=j;k>i;k--){
			if(compare(&array[k],&array[k-1]) < 0){
				swap(&array[k],&array[k-1]);
			}
		}

		for(k=i+1;k<j;k++){
			if(compare(&array[k],&array[k+1]) > 0){
				swap(&array[k],&array[k+1]);		
			}	
		}
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

	shaker_sort(array,0,N-1);

	print_array(array,N);

	return(0);
}
