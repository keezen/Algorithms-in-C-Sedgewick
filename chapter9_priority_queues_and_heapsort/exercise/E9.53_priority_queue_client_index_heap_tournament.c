#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"pqueue_index.h"
#include"item.h"

#define Nmax 100
#define N 12

int compare_index(int index1,int index2);
void print_index(int index);
void print_array(item_t *array,int n_elements);

item_t data[N];

int main(int argc,char *argv[])
{
	item_t string[N+1]="EASYQUESTION";
	int i,t;

	pqueue_init(Nmax);

	for(i=0;i<N;i++){
		data[i]=string[i];
	}
	print_array(data,N);

	pqueue_construct(0,N-1);
	pqueue_print();

	t=pqueue_del_max();
	pqueue_print();
	
	pqueue_insert(t);
	pqueue_print();

	data[10]='P';
	pqueue_change(10);
	pqueue_print();

	pqueue_delete(1);
	pqueue_print();

	return(0);
}

int compare_index(int index1,int index2)
{
	return(compare_item(data[index1],data[index2]));
}

void print_index(int index)
{
	print_item(data[index]);
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
