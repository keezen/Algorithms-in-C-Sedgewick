/*
** This program sorts an array of 32-bit words using the following abstract operation:
** given a bit position i, rearrange the array's i-th bits in a stable manner such that
** those words with a 0 bit in position i appear before those words with a 1 bit in
** position i.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"
#include"radix.h"

void print_array(item_t *array,int n_elements);
void lsd_radixsort(item_t *array,int left,int right);
void rearrange_byte(item_t *array,int left,int right,int w);
void insertion_sort_radix(item_t *array,int left,int right,int w);


int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	item_t *array=malloc(N*sizeof(item_t));
	int i;

	srand((unsigned)time(NULL));	

	for(i=0;i<N;i++){
		array[i]=rand()%N;
	}
//	print_array(array,N);

	lsd_radixsort(array,0,N-1);
//	print_array(array,N);

	return(0);
}


void print_array(item_t *array,int n_elements)
{
	int i;

	for(i=0;i<n_elements;i++){
		print_item(array[i]);
		putchar(' ');
	}
	putchar('\n');
}

/*
** This LSD radix sort is implemented by an abstract operation, i.e., rearranging the
** w-th byte in a stable way. We don't care about how this rearranging operation is
** implemented, it works as long as it is stable.
*/
void lsd_radixsort(item_t *array,int left,int right)
{
	int w;

	for(w=bytesword-1;w>=0;w--){
		rearrange_byte(array,left,right,w);
	}
}

/*
** The abstract rearrange_byte operation is implemented by insertion sort on the given
** byte, in this case.
*/
void rearrange_byte(item_t *array,int left,int right,int w)
{
	insertion_sort_radix(array,left,right,w);
}

void insertion_sort_radix(item_t *array,int left,int right,int w)
{
	int i,j;
	item_t t;

	for(i=left+1;i<=right;i++){
		copy_item(&t,&array[i]);

		for(j=i;j>left;j--){
			if(digit(array[j-1],w)<=digit(t,w)){
				break;
			}

			copy_item(&array[j],&array[j-1]);
		}

		copy_item(&array[j],&t);
	}
}
