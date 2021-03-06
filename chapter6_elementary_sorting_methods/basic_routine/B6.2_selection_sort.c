#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int item_t;

int compare(void *a,void *b);
void swap(void *a,void *b);
void selection_sort(item_t *array,int left,int right);
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

void selection_sort(item_t *array,int left,int right)
{
	int i,j;
	int min;

	for(i=left;i<right;i++){
		min=i;

		for(j=i+1;j<=right;j++){
			if(compare(&array[j],&array[min]) < 0){
				min=j;
			} 
		}

		swap(&array[i],&array[min]);
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

	selection_sort(array,0,N-1);

	print_array(array,N);

	return(0);
}
