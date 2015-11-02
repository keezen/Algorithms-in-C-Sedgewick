/*
** This program implements the bin-span heuristic to sort 30-byte keys of radix 256. Only 
** the bins for uppercase letters are not empty, i.e., when bytes range from 'A' to 'Z'.
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

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	item_t *array=malloc(N*sizeof(item_t));
	int i;

	srand((unsigned)time(NULL));	

	for(i=0;i<N;i++){
		rand_item(&array[i]);
	}
	print_array(array,N);

	msd_radixsort(array,0,N-1);
	print_array(array,N);

	return(0);
}

void print_array(item_t *array,int n_elements)
{
	int i;

	for(i=0;i<n_elements;i++){
		print_item(&array[i]);
		putchar('\n');
	}
	putchar('\n');
}

void msd_radixsort(item_t *array,int left,int right)
{
	do_msd_radixsort(array,left,right,0);
}

/*
** This MSD radix sort implementation uses th bin-span heuristic: keep track
** of the high and low ends of the range of nonemptybins, i.e., bin_max and
** bin_min, during the counting phase, then use only bins in that range (perhaps
** also including special cases for a few special key values, such as 0 or blank).
*/
void do_msd_radixsort(item_t *array,int left,int right,int w)
{
	int n=right-left+1;
	item_t *aux;
	int count[R];
	int bin_min,bin_max;
	int i;

	if(right-left+1<=1 || w>=bytesword){
		return;
	}


	for(i=0;i<R;i++){
		count[i]=0;
	}

	for(i=left;i<=right;i++){
		count[digit(array[i],w)]++;
	}

	for(i=0;count[i]==0;i++)
		;
	bin_min=i;
	for(i=R-1;count[i]==0;i--)
		;
	bin_max=i;

	for(i=bin_max;i>bin_min;i--){
		count[i]=count[i-1];
	}
	count[bin_min]=0;

	for(i=bin_min+1;i<=bin_max;i++){
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

	
	do_msd_radixsort(array,left,left+count[bin_min]-1,w+1);
	for(i=bin_min+1;i<=bin_max;i++){
		do_msd_radixsort(array,left+count[i-1],left+count[i]-1,w+1);		
	}
}

void rand_item(item_t *x)
{
	int i;

	for(i=0;i<bytesword;i++){
		(*x)[i]=rand()%26+'A';
	}
}
