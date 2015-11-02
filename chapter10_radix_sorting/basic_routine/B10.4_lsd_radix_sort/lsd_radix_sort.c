/*
** This program implements LSD radix sort by key-indexed counting on the bytes, moving
** from right to the left. The key-indexed counting implementation must be stable.
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
** This function implements LSD radix sort by key-indexed counting from right to
** left. We sort the file according to the final byte, then according to the middle
** bytes, then according to the first byte. The method requires that the key-indexed
** counting is stable. Once stability is satisfied, we can prove that this method does
** work: suppose we have put the i trailing bytes in order, when we are sorting the
** (i+1)th trailing byte by key-indexed counting, since the key-indexed counting method
** is stable, the (i+1) trailing bytes will be in order. Repeat this induction, we can
** get that after we move from right to left, reaching the first byte, all the bytes will
** be sorted, so that the keys is sorted.
*/
void lsd_radixsort(item_t *array,int left,int right)
{
	int i;
	int w;
	int n=right-left+1;
	int count[R+1];
	item_t *aux;

	if(right-left+1<=1){
		return;
	}


	aux=malloc(n*sizeof(*aux));

	for(w=bytesword-1;w>=0;w--){
		for(i=0;i<=R;i++){
			count[i]=0;
		}
	
		for(i=left;i<=right;i++){
			count[digit(array[i],w)+1]++;
		}
	
		for(i=1;i<=R;i++){
			count[i]+=count[i-1];
		}


		for(i=left;i<=right;i++){
			copy_item(&aux[count[digit(array[i],w)]++],&array[i]);
		}
	
		for(i=left;i<=right;i++){
			copy_item(&array[i],&aux[i-left]);	
		}
	}

	free(aux);
}
