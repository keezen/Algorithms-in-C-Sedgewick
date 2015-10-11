#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SEQUENCE 100

int sequences[MAX_SEQUENCE]={1,8,23,77};
int n;
int count_cmp;

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

	n=4;
	for(k=n-1;k>=0;k--){
		h=sequences[k];

		for(i=left+h;i<=right;i++){
			temp=array[i];

			for(j=i-h;j>=left && (count_cmp++,compare(&array[j],&temp)>0);j-=h){
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
	int N=100;
	item_t *array=malloc(N*sizeof(*array));
	item_t *array_2=malloc(N*sizeof(*array_2));
	int i,j;
	int max_cmp;

	srand((unsigned)time(NULL));

	max_cmp=-1;
	for(j=0;j<3;j++){
		count_cmp=0;

		if(j==0){
			for(i=0;i<N;i++){
				array[i]=rand()%N;
			}
			
			printf("random: ");
		}
		if(j==1){
			for(i=0;i<N;i++){
				array[i]=N-i;
			}
			printf("reverse order: ");
		}
		if(j==2){
			for(i=0;i<N;i++){
				array[i]=i;
			}			
			printf("in order: ");
		}

		shell_sort(array,0,N-1);
	
		if(count_cmp>max_cmp){
			max_cmp=count_cmp;
			copy_array(array_2,array,N);	
		}

		printf("%d\n",count_cmp);
	}

	putchar('\n');
	printf("max_cmp: %d\n",max_cmp);

	return(0);
}
