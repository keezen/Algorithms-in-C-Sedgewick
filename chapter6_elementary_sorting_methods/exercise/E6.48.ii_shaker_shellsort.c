#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SEQUENCE 100

int sequences[MAX_SEQUENCE]={1,4,13,40,121,364,1093,3280,9841,29524};
int n=9;

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

	for(k=n-1;k>=0;k--){
		h=sequences[k];

		for(i=left+h;i<=right;i++){
			temp=array[i];

			for(j=i-h;j>=left && compare(&array[j],&temp)>0;j-=h){
					array[j+h]=array[j];
			}

			array[j+h]=temp;
		}
	}	
}

void shaker_shellsort(item_t *array,int left,int right)
{
	int h;
	int i,j,k;
	item_t temp;

	for(k=n-1;k>=0;k--){
		h=sequences[k];

		for(i=left+h;i<=right;i++){
			temp=array[i];

			for(j=i-h;j>=left && compare(&array[j],&temp)>0;j-=h){
					array[j+h]=array[j];
			}

			array[j+h]=temp;
		}

		if(k==0){
			break;
		}

		h=sequences[--k];

		for(i=right-h;i>=left;i--){
			temp=array[i];

			for(j=i+h;j<=right && compare(&array[j],&temp)<0;j+=h){
					array[j-h]=array[j];
			}

			array[j-h]=temp;
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
	double sort_time;

	srand((unsigned)time(NULL));

	for(i=0;i<N;i++){
		array[i]=rand()%N;
	}

	copy_array(array_2,array,N);

	for(i=0;sequences[i]<N;i++)
		;
	n=i;

	for(i=0;i<2;i++){
		copy_array(array,array_2,N);

		c1=clock();
		if(i==0){
			shell_sort(array,0,N-1);
			printf("shell sort\n");
		}
		if(i==1){
			shaker_shellsort(array,0,N-1);
			printf("shaker shellsort\n");
		}
		c2=clock();
	
		sort_time=(double)(c2-c1)/CLOCKS_PER_SEC;
		print_array(sequences,n);
		printf("sort time: %fs\n\n",sort_time);
	}

	return(0);
}
