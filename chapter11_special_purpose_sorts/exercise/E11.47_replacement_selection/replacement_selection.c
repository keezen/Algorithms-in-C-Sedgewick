/*
** This program generates a file of N items, and then prints out the average number
** of runs produced using replacement selection with a priority queue of size 1000.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"item.h"
#include"pqueue.h"

#define MAX_ELEMENT 2000000
#define MAX_RUN 10000
#define PQUEUE_SIZE 1000


void print_array(item_t *array,int n_elements);
int replacement_selection(item_t *strings,int n_elements);

item_t buf[MAX_ELEMENT]={0};
item_t *runs[MAX_RUN];


int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	item_t *strings;
	int i,n_run;

	srand((unsigned)time(NULL));
	strings=malloc(N*sizeof(*strings));

	for(i=0;i<N;i++){
		strings[i]=rand()%26+'A';
	}

/*	printf("input: ");
	print_array(strings,N);
	putchar('\n');
*/

	n_run=replacement_selection(strings,N);

	printf("the number of runs: %d\n",n_run);
/*	for(i=0;i<n_run;i++){
		printf("%d: %s\n",i,runs[i]);
	}
*/
	return(0);
}


void print_array(item_t *array,int n_elements)
{
	int i;

	for(i=0;i<n_elements;i++){
		print_item(&array[i]);
		putchar(' ');
	}
	putchar('\n');
}

/*
** This function produces a sequence of sorted runs using replacement selection, given
** an input file. The main idea is to pass the unordered input through a large priority
** queue, always writing out the smallest element on the priority queue as before, and
** always replacing it with the next element from the input, with one additional proviso:
** If the new element is smaller than the one output most recently, we mark it as a member
** of the next block and treat is as greater than all elements in the current block. When
** a marked element makes it to the top of the priority queue, we begin a new block.
*/
int replacement_selection(item_t *strings,int n_elements)
{
	pqueue_item_t output,input;
	int i,j,n_run=0;

	pqueue_init(PQUEUE_SIZE);

	/* Fill the priority queue. */
	for(i=0;i<PQUEUE_SIZE && i<n_elements;i++){
		input.item=strings[i];
		input.block=0;

		pqueue_insert(input);
	}

	/*
	** Write out the minimum element in the priority queue, and
	** replace it with the next elment from the input.
	*/
	j=0;
	n_run=0;
	runs[n_run]=buf;
	for(;i<n_elements;i++){
		output=pqueue_min();

		if(output.block == n_run){
			buf[j++]=output.item;
		}else{
			buf[j++]=0;
			buf[j++]=output.item;

			runs[++n_run]=&buf[j-1];
		}


		input.item=strings[i];

		if(compare_item(&input.item,&output.item)<0){
			input.block=output.block+1;
		}else{
			input.block=output.block;
		}

		pqueue_replace_min(input);		
	}

	
	/* Empty the priority queue. */
	while(!pqueue_empty()){
		output=pqueue_del_min();

		if(output.block == n_run){
			buf[j++]=output.item;
		}else{
			buf[j++]=0;
			buf[j++]=output.item;

			runs[++n_run]=&buf[j-1];
		}
	}
	buf[j++]=0;
	runs[++n_run]=&buf[j];


	return(n_run);
}
