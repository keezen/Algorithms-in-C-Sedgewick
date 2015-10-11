#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

typedef int item_t;

int compare(void *a,void *b);
void swap(void *a,void *b);
void shell_sort(item_t *array,int left,int right);
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

void shell_sort(item_t *array,int left,int right)
{
	int h,k;
	int i,j;
	item_t temp;

	for(k=0;(h=pow(4,k+1)+3*pow(2,k)+1) <= right-left;k++)
		;
	k--;

	for(;k>=-1;k--){
		if(k>=0){
			h=pow(4,k+1)+3*pow(2,k)+1;
		}else{
			h=1;
		}

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

	shell_sort(array,0,N-1);

	print_array(array,N);

	return(0);
}
