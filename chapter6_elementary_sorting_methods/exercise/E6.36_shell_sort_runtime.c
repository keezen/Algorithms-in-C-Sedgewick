#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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
	int h;
	int i,j;
	item_t temp;

	for(h=1;h<=(right-left)/4;h*=2)
		;

	for(;h>0;h/=2){
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
	clock_t c1,c2;
	
	for(i=0;i<2*N;i++){
		if(i%2==1){
			array[i]=(i+1)/2;
		}else{
			array[i]=i/2+1+N;
		}
	}

	c1=clock();
	shell_sort(array,0,2*N-1);
	c2=clock();

	printf("sort time: %.3fs\n",(double)(c2-c1)/CLOCKS_PER_SEC);

	return(0);
}
