/*
** This program generates N 3-byte keys with R=10, but the first byte only allows 0 and 1.
** Then rearrange the file such that all those whose keys begin with a 0 byte come before
** all those keys begin with a 1 byte. This method uses no extra space, and is stable, which
** is implemented by insertion sort on the given byte.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"
#include"radix.h"

void print_array(item_t *array,int n_elements);
void insertion_sort_radix(item_t *array,int left,int right,int w);
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

	insertion_sort_radix(array,0,N-1,0);
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

/*
** This insertion_sort_radix functions sorts the keys on the given w-th byte.
*/
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

/*
** This generator generates a key begin with 0 or 1, and the other bytes
** are ranging from 0 to R-1.
*/
void rand_item(item_t *x)
{
	int i;

	(*x)[i]=rand()%2;
	for(i=1;i<bytesword;i++){
		(*x)[i]=rand()%R;
	}
}
