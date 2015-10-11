#include<stdio.h>
#include<stdlib.h>
#include"item.h"

#define N 10
#define M 3

item_t **key_index_count_sort(item_t array[],int left,int right);
void print_array(item_t array[],int n_elements);
void print_array_pointer(item_t *array[],int n_elements);

/*
** Sort the item array by key-indexed sort. We don't move the
** element virtually, but store the sorted pointers in the array
** b, whose element has the type of item_t *. The return value is
** of the type item_t **, that is an array of item_t * actually.
*/
item_t **key_index_count_sort(item_t array[],int left,int right)
{
	int count[M];
	item_t **b=malloc(N*sizeof(*b));
	int i;

	for(i=0;i<M;i++){
		count[i]=0;
	}

	for(i=left;i<=right;i++){
		count[key_item(array[i])+1]++;
	}

	for(i=1;i<M;i++){
		count[i]+=count[i-1];	
	}

	for(i=left;i<=right;i++){
		b[count[key_item(array[i])]++]=&array[i];
	}

	return(b);
}

void print_array(item_t array[],int n_elements)
{
	int i;
	
	for(i=0;i<n_elements;i++){
		print_item(array[i]);
		putchar(' ');
	}
	putchar('\n');
}

void print_array_pointer(item_t *array[],int n_elements)
{
	int i;
	
	for(i=0;i<n_elements;i++){
		print_item(*array[i]);
		putchar(' ');
	}
	putchar('\n');
}

int main(void)
{
	item_t array[N]={
		{'A',1},
		{'B',1},
		{'C',1},
		{'D',1},
		{'E',2},
		{'F',2},
		{'G',2},
		{'H',2},
		{'I',0},
		{'J',0},
	};
	item_t **sorted;

	print_array(array,N);	
	
	sorted=key_index_count_sort(array,0,N-1);
	print_array_pointer(sorted,N);

	return(0);
}
