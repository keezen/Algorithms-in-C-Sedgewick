/*
** This program implements the Pratt's shellsort and counts the number of comparators
** in the Pratt's sorting network.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

#define N_MAX 1000
#define N_INCREMENT 26

void print_array(item_t *array,int n_elements);
void pratt_shellsort(item_t *array,int left,int right);

/* Pratt's shellsort increments. */
int increments[N_INCREMENT]=
	{1,2,3,4,6,
	9,8,12,18,27,
	16,24,36,54,81,
	32,48,72,108,162,
	243,64,96,144,216,
	324};
int used[N_MAX+1]={0};
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
//	print_array(array,N);
	
	pratt_shellsort(array,0,N-1);
//	print_array(array,N);
	printf("the number of comparators: %d\n",count_comp++);

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

/*
** The Pratt's shellsort is essentially a kind of shellsort with specific increments.
** The main idea is: if a file is 2x-ordered and 3x-ordered, you just need to move every
** element at most one position when you are x-sorting the file.
*/
void pratt_shellsort(item_t *array,int left,int right)
{
	int n=right-left+1;
	int i,j,k,h;

	for(i=0;i<N_INCREMENT;i++){
		if(increments[i]>n){
			break;
		}
	}
	i--;

	for(;i>=0;i--){
		h=increments[i];

		if(used[2*h]!=0 && used[3*h]!=0){
			for(j=left+h;j<=right;j++){
				compare_swap_item(&array[j-h],&array[j]);
				count_comp++;
			}
		}else{
			for(j=left+h;j<=right;j++){
				for(k=j;k>=left+h;k-=h){
					compare_swap_item(&array[k-h],&array[k]);
					count_comp++;
				}
			}
		}

		used[h]=1;
	}
}
