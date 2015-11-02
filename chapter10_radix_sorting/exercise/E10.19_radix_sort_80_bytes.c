/*
** This program generates N random 80-byte keys, then sort them with MSD radix
** sort and print out the total number of bytes examined for the sort. The 80-byte
** key is implemented by a char array whose size is 80. 
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"
#include"radix.h"

void print_array(item_t *array,int n_elements);
void msd_radixsort(item_t *array,int left,int right);
void do_msd_radixsort(item_t *array,int left,int right,int w);
void rand_item(item_t *x);

int count_bytes=0;

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	item_t *array=malloc(N*sizeof(item_t));
	int i;

	srand((unsigned)time(NULL));	

	for(i=0;i<N;i++){
		rand_item(&array[i]);
	}
//	print_array(array,N);

	msd_radixsort(array,0,N-1);
//	print_array(array,N);
	printf("number of bytes examined: %d\n",count_bytes);

	return(0);
}

void print_array(item_t *array,int n_elements)
{
	int i;

	for(i=0;i<n_elements;i++){
		print_item(&array[i]);
		putchar(' ');
	}
	putchar('\n');
}

void msd_radixsort(item_t *array,int left,int right)
{
	do_msd_radixsort(array,left,right,0);
}

void do_msd_radixsort(item_t *array,int left,int right,int w)
{
	int n=right-left+1;
	item_t *aux;
	int count[R];
	int i;

	if(right-left+1<=1 || w>=bytesword){
		count_bytes+=0;
		return;
	}


	for(i=0;i<R;i++){
		count[i]=0;
	}

	for(i=left;i<=right;i++){
		count[digit(array[i],w)+1]++;
	}

	for(i=1;i<R;i++){
		count[i]+=count[i-1];
	}


	aux=malloc(n*sizeof(*aux));

	for(i=left;i<=right;i++){
		copy_item(&aux[count[digit(array[i],w)]++],&array[i]);
	}

	for(i=left;i<=right;i++){
		copy_item(&array[i],&aux[i-left]);	
	}

	free(aux);

	
	do_msd_radixsort(array,left,left+count[0]-1,w+1);
	for(i=1;i<R;i++){
		do_msd_radixsort(array,left+count[i-1],left+count[i]-1,w+1);		
	}

	count_bytes+=n;
}

void rand_item(item_t *x)
{
	int i;

	for(i=0;i<bytesword;i++){
		(*x)[i]=rand()%R;
	}
}
