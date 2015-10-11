#include<stdio.h>
#include"item.h"

#define N 10
#define M 3

void key_index_count_sort(item_t array[],int left,int right);
void print_array(item_t array[],int n_elements);

void key_index_count_sort(item_t array[],int left,int right)
{
	int count[M];
	item_t b[N];
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
		copy_item(&b[count[key_item(array[i])]++],&array[i]);
	}

	for(i=left;i<=right;i++){
		copy_item(&array[i],&b[i-left]);
	}
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

	print_array(array,N);	
	
	key_index_count_sort(array,0,N-1);
	print_array(array,N);

	return(0);
}
