/*
** This program sorts the 32-bit keys by LSD radix sort, whose inner loop
** has less instructions than the standard LSD.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"
#include"radix.h"

void print_array(item_t *array,int n_elements);
void lsd_radixsort(item_t *array,int left,int right);


int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	item_t *array=malloc(N*sizeof(*array));
	int i;

	srand((unsigned)time(NULL));	

	for(i=0;i<N;i++){
		array[i]=rand()%N;
	}
	print_array(array,N);

	lsd_radixsort(array,0,N-1);
	print_array(array,N);

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
** This lsd_radixsort implementation uses a stable sorting method to make
** the w-th byte in order. We use two traversing pointer i, j to find bit
** 0 and 1 in the byte, and put them in the right places in the auxiliary
** array aux from both ends, pointed to by p and q. When the traverse is 
** finished, then the w-th byte is in order. This method is stable, but it
** can only sorts the byte that just has 1 bit in size, whose value is either
** 0 or 1.
*/
void lsd_radixsort(item_t *array,int left,int right)
{
	int i,j;
	int p,q;
	int w;
	int n=right-left+1;
	item_t *aux;

	if(right-left+1<=1){
		return;
	}


	aux=malloc(n*sizeof(*aux));

	for(w=bytesword-1;w>=0;w--){
		p=0;
		q=n-1;
		for(i=left,j=right;i<=right;i++,j--){
			if(digit(array[i],w)==0){
				copy_item(&aux[p++],&array[i]);
			}
			if(digit(array[j],w)==1){
				copy_item(&aux[q--],&array[j]);
			}
		}

		for(i=left;i<=right;i++){
			copy_item(&array[i],&aux[i-left]);
		}
	}

	free(aux);
}
