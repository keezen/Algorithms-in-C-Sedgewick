/*
** This program computes the number of passes for multiway merging, given the
** number of devices 2P and the number of initial blocks.
*/
#include<stdio.h>
#include<stdlib.h>

/* This macro P represents 2P external devices. */
#define P 100

int multiway_merge_pass(int n_block);


int main(int argc,char *argv[])
{
	int n_pass;
	int n_block=atoi(argv[1]);

	n_pass=multiway_merge_pass(n_block);

	printf("the number of blocks: %d\n",n_block);
	printf("the number of passes: %d\n",n_pass);

	return(0);
}


int multiway_merge_pass(int n_block)
{
	int i;
	int product;

	product=1;
	for(i=0;product<n_block;i++){
		product*=P;
	}

	return(i);
}
