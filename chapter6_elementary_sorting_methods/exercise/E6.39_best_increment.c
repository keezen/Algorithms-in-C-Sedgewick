#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SEQUENCE 100

int sequences[MAX_SEQUENCE]={1,4,13,40,121,364,1093,3280,9841};

typedef int item_t;

int compare(void *a,void *b);
void swap(void *a,void *b);
void shell_sort(item_t *array,int left,int right);
void print_array(item_t *array,int n_elements);
void copy_array(item_t *dst,item_t *src,int n_elements);

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

void shell_sort(item_t *array,int left,int right)
{
	int h;
	int i,j,k;
	item_t temp;
	int n;

	n=9;
	for(n--;n>=0;n--){
		h=sequences[n];

		for(i=left+h;i<=right;i++){
			temp=array[i];

			for(j=i-h;j>=left && compare(&array[j],&temp)>0;j-=h){
					array[j+h]=array[j];
			}

			array[j+h]=temp;
		}
	}	
}

void print_array(item_t *array,int n_elements)
{
	int i;

	for(i=0;i<n_elements;i++)
		printf("%d ",array[i]);
	putchar('\n');
}

void copy_array(item_t *dst,item_t *src,int n_elements)
{
	int i;

	for(i=0;i<n_elements;i++){
		dst[i]=src[i];
	}
}

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	item_t *array=malloc(N*sizeof(*array));
	item_t *array_2=malloc(N*sizeof(*array_2));
	int i;
	clock_t c1,c2;
	int x,min;
	double lowest_time;
	double sort_time;

	srand((unsigned)time(NULL));

	for(i=0;i<N;i++){
		array[i]=rand()%N;
	}

	copy_array(array_2,array,N);

	lowest_time=100;
	min=0;
	for(x=5;x<40;x++){
		copy_array(array,array_2,N);
	
		sequences[2]=x;

		c1=clock();
		shell_sort(array,0,N-1);
		c2=clock();
	
		sort_time=(double)(c2-c1)/CLOCKS_PER_SEC;
		if(sort_time<lowest_time){
			lowest_time=sort_time;
			min=x;	
		}
	}

	printf("best x: %d\n",min);
	printf("lowest_time: %fs\n",lowest_time);

	return(0);
}
