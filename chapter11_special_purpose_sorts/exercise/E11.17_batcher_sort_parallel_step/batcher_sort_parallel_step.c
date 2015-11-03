/*
** This program computes the number of parallel steps required for the Batcher's sort.
** The followig labeling strategy is used: label the input lines as belonging to stage
** 0, then for each comparator, label both ouput lines as inputs to stage i+1 if the
** label on one of the input lines is i and the label on the other is not greater than i.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

void print_array(item_t *array,int n_elements);
void batcher_sort(item_t *array,int left,int right);

int *label;

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);	
	item_t *array=malloc(N*sizeof(*array));
	int i;
	int max_label;

	srand((unsigned)time(NULL));

	label=malloc(N*sizeof(int));
	for(i=0;i<N;i++){
		array[i]=rand()%N;
		label[i]=0;
	}
	print_array(array,N);
	
	batcher_sort(array,0,N-1);
	print_array(array,N);

	max_label=label[0];
	for(i=1;i<N;i++){
		if(label[i]>max_label){
			max_label=label[i];
		}
	}
	printf("the number of parallel steps: %d\n",max_label);

	free(array);
	free(label);

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
	int next_label;

	for(p=1;p<n;p*=2){
		for(k=p;k>0;k/=2){
			for(j=k%p;j+k<n;j+=2*k){
				for(i=0;i<k;i++){
					if(j+i+k<n){
						if((j+i)/(p+p) == (j+i+k)/(p+p)){
							compare_swap_item(&array[left+j+i],&array[left+j+i+k]);

							if(label[left+j+i]>label[left+j+i+k]){
								next_label=label[left+j+i]+1;
							}else{
								next_label=label[left+j+i+k]+1;
							}
							label[left+j+i]=label[left+j+i+k]=next_label;
						}
					}
				}
			}
		}
	}
}
