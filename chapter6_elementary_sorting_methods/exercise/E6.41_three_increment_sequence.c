#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define MAX_SEQUENCE 100

int sequences[MAX_SEQUENCE];
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
	int N=atoi(argv[1]);
	item_t *array=malloc(N*sizeof(*array));
	item_t *array_2=malloc(N*sizeof(*array_2));
	int i;
	int a,b,min_a,min_b;
	int min_cmp;

	srand((unsigned)time(NULL));

	for(i=0;i<N;i++){
		array[i]=rand()%N;
	}

	copy_array(array_2,array,N);

	sequences[0]=1;
	n=3;
	min_a=0;
	min_b=0;
	min_cmp=-1;
	for(a=2;a<50;a++){
		for(b=a+1;b<100;b+=1){
			count_cmp=0;

			copy_array(array,array_2,N);
		
			sequences[1]=a;
			sequences[2]=b;
	
			shell_sort(array,0,N-1);
		
			if(min_cmp==-1 || count_cmp<min_cmp){
				min_cmp=count_cmp;
				min_a=a;
				min_b=b;	
			}
		}
	}

	printf("best a: %d\n",min_a);
	printf("best b: %d\n",min_b);
	printf("min_cmp: %d\n",min_cmp);

	return(0);
}
