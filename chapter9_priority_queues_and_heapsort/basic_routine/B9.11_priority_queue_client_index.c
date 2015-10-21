#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"pqueue_index.h"
#include"item.h"

#define N 13

int compare_index(int index1,int index2);
void print_index(int index);
void print_array(item_t *array,int n_elements);

item_t *data;

int main(void)
{
	int i,t;
	item_t string[N+1]="XSPGRONAEBAIM";

	srand((unsigned)time(NULL));
	pqueue_init(N);
	data=malloc(N*sizeof(*data));

	for(i=0;i<N;i++){
		data[i]=string[i];
	}
	print_array(data,N);

	for(i=0;i<N;i++){
		pqueue_insert(i);
	}
	pqueue_print();

	data[9]='T';
	pqueue_change(9);
	pqueue_print();

	pqueue_delete(0);
	pqueue_print();

	while(!pqueue_empty()){
		t=pqueue_del_max();
		print_item(data[t]);
		putchar(' ');
	}
	putchar('\n');

	return(0);
}

int compare_index(int index1,int index2)
{
	return(compare_item(data[index1],data[index2]));
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

void print_index(int index)
{
	print_item(data[index]);
}
