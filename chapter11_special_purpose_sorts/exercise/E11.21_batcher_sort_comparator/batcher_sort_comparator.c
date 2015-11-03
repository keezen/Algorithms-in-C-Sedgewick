/*
** This program prints out the number of comparators for the sorting networks that 
** sort N elements.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

/*
** The macro DISPLACEMENT indicates the displacement of the sorting network for N
** elements from the full network for the smallest power of 2 greater than or equal
** to N. You can visualize the N-network as a cutoff from the 2-power-network.
*/
#define DISPLACEMENT 7


void print_array(item_t *array,int n_elements);
void batcher_sort(item_t *array,int left,int right);

int count_comp=0;


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
	
	batcher_sort(array,0,N-1);
	print_array(array,N);
	printf("the number of copmarators: %d\n",count_comp);

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
			for(j=k%p;j+k<n+DISPLACEMENT;j+=2*k){
				for(i=0;i<k;i++){
					if(j+i>=DISPLACEMENT && j+i+k<n+DISPLACEMENT){
						if((j+i)/(p+p) == (j+i+k)/(p+p)){
							compare_swap_item(&array[left-DISPLACEMENT+j+i],&array[left-DISPLACEMENT+j+i+k]);

							count_comp++;
						}
					}
				}
			}
		}
	}
}
