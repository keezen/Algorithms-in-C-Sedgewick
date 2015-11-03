/*
** This program prints out the number of comparators in Batcher's odd-even sorting
** networks for N between 2 to 32, where networks when N is not a power of 2 are derived
** from the first N lines of the network for the next largest power of 2.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

#define NMAX 32


void print_array(item_t *array,int n_elements);
void batcher_sort(item_t *array,int left,int right);

int count_comp;


int main(int argc,char *argv[])
{
	int N;	
	item_t *array=malloc(NMAX*sizeof(*array));
	int i;

	srand((unsigned)time(NULL));

	for(i=0;i<NMAX;i++){
		array[i]=rand()%NMAX;
	}
//	print_array(array,NMAX);

	printf("N\tCount\n");
	for(N=2;N<=NMAX;N++){
		count_comp=0;
	
		batcher_sort(array,0,N-1);

		printf("%d\t%d\n",N,count_comp);
	}

//	print_array(array,NMAX);

	free(array);

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

void batcher_sort(item_t *array,int left,int right)
{
	int i,j,k,p;
	int n=right-left+1;

	for(p=1;p<n;p*=2){
		for(k=p;k>0;k/=2){
			for(j=k%p;j+k<n;j+=2*k){
				for(i=0;i<k;i++){
					if(j+i+k<n){
						if((j+i)/(p+p) == (j+i+k)/(p+p)){
							compare_swap_item(&array[left+j+i],&array[left+j+i+k]);
							
							count_comp++;
						}
					}
				}
			}
		}
	}
}
