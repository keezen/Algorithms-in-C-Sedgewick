#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"
#include"radix.h"

void print_array(item_t *array,int n_elements);
void binary_quicksort(item_t *array,int left,int right);
void do_binary_quicksort(item_t *array,int left,int right,int w);

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

	binary_quicksort(array,0,N-1);
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

void binary_quicksort(item_t *array,int left,int right)
{
	do_binary_quicksort(array,left,right,0);
}

/*
** This do_binary_quicksort function partitions a file on the leading bits of the
** the keys, and then sorts the subfiles recursively. The variable w keeps track of
** the bit being examined, starting at 0 (leftmost). The partitioning stops when i>=j
** , just like quicksort, and all elements to the left of a[i] having 0 bits in the
** w-th position. The element a[i] itself will have a 1 bit unless all keys in the file 
** have a 0 bit.
*/
void do_binary_quicksort(item_t *array,int left,int right,int w)
{
	int i,j;

	if(right-left+1<=1 || w>=bytesword){
		return;
	}


	i=left;
	j=right;
	while(1){
		for(;i<=right && digit(array[i],w)!=1;i++)
			;
		for(;j>=left && digit(array[j],w)!=0;j--)
			;

		if(i>=j){
			break;
		}

		swap_item(&array[i],&array[j]);
		i++;
		j--;
	}

	do_binary_quicksort(array,left,i-1,w+1);
	do_binary_quicksort(array,i,right,w+1);
}
