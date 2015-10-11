#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int item_t;

int compare(void *a,void *b);
void swap(void *a,void *b);
void bubble_sort(item_t *array,int left,int right);
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

void bubble_sort(item_t *array,int left,int right)
{
	int i,j;
	int n_swap;

	for(i=left;i<right;i++){
		n_swap=0;

		for(j=right;j>i;j--){
			if(compare(&array[j],&array[j-1]) < 0){
				swap(&array[j],&array[j-1]);
				n_swap++;
			}
		}

		if(n_swap==0)
			break;
	}
	
	printf("number of passes: %d\n",i-left+1);
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

	printf("N: %d\n",N);
	
	bubble_sort(array,0,N-1);

	return(0);
}
