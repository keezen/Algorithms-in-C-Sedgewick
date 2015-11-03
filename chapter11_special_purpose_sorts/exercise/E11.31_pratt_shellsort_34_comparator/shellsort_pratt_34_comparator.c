/*
** This program implements the Pratt's shellsort and counts the number of comparators
** in the Pratt's sorting network.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

#define N_MAX 1000
#define N_INCREMENT 19

void print_array(item_t *array,int n_elements);
void pratt_shellsort(item_t *array,int left,int right);

/* Pratt's shellsort increments. */
int increments[N_INCREMENT]=
	{1,3,4,9,12,
	16,27,36,48,64,
	81,108,144,192,256,
	243,324,432,576};
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
	print_array(array,N);
	
	pratt_shellsort(array,0,N-1);
	print_array(array,N);
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
** The main idea is: if a file is 3x-ordered and 4x-ordered, you just need to move every
** element at most three positions when you are x-sorting the file.
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

		if(3*h<=N_MAX && 4*h<=N_MAX && used[3*h]!=0 && used[4*h]!=0){
			for(j=left+h;j<=right;j++){
				for(k=j;k>=left+h && k>=j-2*h;k-=h){
					compare_swap_item(&array[k-h],&array[k]);
					count_comp++;
				}
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
