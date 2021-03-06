/*
** This programs radix sort a file of N random 32-bit integers, with the bytesize is 1 bit,
** i.e., R=2. Then compute the number of digits examined.
*/
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"radix.h"

typedef int item_t;

void print_array(item_t *array,int n_elements);
int radix_sort(item_t *array,int left,int right);
int do_radix_sort(item_t *array,int left,int right,int w);

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	item_t *array=malloc(N*sizeof(*array));
	int i;
	int digit_comp;

	for(i=0;i<N;i++){
		array[i]=rand();
	}
//	print_array(array,N);

	digit_comp=radix_sort(array,0,N-1);
//	print_array(array,N);
	printf("number of digit comparisons: %d\n",digit_comp);

	return;
}

void print_array(item_t *array,int n_elements)
{
	int i;

	for(i=0;i<n_elements;i++){
		printf("%d ",array[i]);
	}
	putchar('\n');
}

int radix_sort(item_t *array,int left,int right)
{
	return(do_radix_sort(array,left,right,0));
}

/*
** This function sorts the array according to the digits from w-th digit to (bytesword-1)-th
** digit. Firstly, we use the key-indexed counting method to divide into R parts in order 
** according the w-th digit. Then we call the function recursively to sort every part.
** Continue this process until the size of the subfile is less than or equal to 1, or
** the all bytesword digits have been examined. By the way, this function returns the number
** of digits examined to sort the array.
*/
int do_radix_sort(item_t *array,int left,int right,int w)
{
	int count[R];
	int n=right-left+1;
	item_t *aux;
	int i;
	int digit_comp=0;

	if(right-left+1<=1 || w>=bytesword){
		return(0);
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
		aux[count[digit(array[i],w)]++]=array[i];
	}

	for(i=left;i<=right;i++){
		array[i]=aux[i-left];
	}

	free(aux);


	digit_comp+=n;
	digit_comp+=do_radix_sort(array,left,left+count[0]-1,w+1);
	for(i=1;i<R;i++){
		digit_comp+=do_radix_sort(array,left+count[i-1],left+count[i]-1,w+1);
	}

	return(digit_comp);
}
