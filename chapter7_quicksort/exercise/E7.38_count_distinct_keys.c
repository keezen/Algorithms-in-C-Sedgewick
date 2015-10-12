#include<stdio.h>
#include<stdlib.h>
#include"item.h"

void print_array(item_t *array,int n_elements);
int count_distinct_keys(item_t *array,int left,int right);

int M;
item_t *existed;

void print_array(item_t *array,int n_elements)
{
	int i;

	for(i=0;i<n_elements;i++){
		print_item(array[i]);
		putchar(' ');
	}
	putchar('\n');
}

int count_distinct_keys(item_t *array,int left,int right)
{
	int i;
	int count;

	existed=malloc(M*sizeof(*existed));
	for(i=0;i<M;i++){
		existed[i]=0;
	}

	for(count=0,i=left;i<=right;i++){
		if(existed[array[i]]==0){
			existed[array[i]]=1;
			count++;
		}
	}
	
	free(existed);

	return(count);
}

int main(int argc,char *argv[])
{
	int N=atoi(argv[2]);
	item_t *array=malloc(N*sizeof(*array));
	int i;

	srand((unsigned)time(NULL));
	M=atoi(argv[1]);

	for(i=0;i<N;i++){
		array[i]=rand()%M;
	}

	printf("number of distinct keys: %d\n",count_distinct_keys(array,0,N-1));

	free(array);

	return(0);
}
