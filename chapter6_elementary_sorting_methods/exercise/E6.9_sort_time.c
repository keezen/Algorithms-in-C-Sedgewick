#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int item_t;

int compare(void *a,void *b);
void swap(void *a,void *b);
void sort(item_t *array,int left,int right);
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

void sort(item_t *array,int left,int right)
{
	int i,j;

	for(i=left+1;i<=right;i++){
		for(j=i;j>left;j--){
			if(compare(&array[j],&array[j-1]) < 0){
				swap(&array[j],&array[j-1]);
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
	clock_t c1,c2;
	
	srand((unsigned)time(NULL));

	for(i=0;i<N;i++){
		array[i]=rand()%100;
	}

	c1=clock();
	sort(array,0,N-1);
	c2=clock();

	printf("sort time: %.3fs\n",(double)(c2-c1)/CLOCKS_PER_SEC);

	return(0);
}
