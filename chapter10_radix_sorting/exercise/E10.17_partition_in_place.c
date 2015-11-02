/*
** This program does R-way partitioning in place, by counting the frequency of
** occurrence of each key as in key-indexed counting, then using a method like
** in-place sorting to move the keys.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

#define R 4

void print_array(item_t *array,int n_elements);
void partition_in_place(item_t *array,int left,int right);

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	int i;
	item_t *array=malloc(N*sizeof(*array));

	srand((unsigned)time(NULL));

	for(i=0;i<N;i++){
		array[i]=rand()%R;
	}
	print_array(array,N);

	partition_in_place(array,0,N-1);
	print_array(array,N);

	return(0);
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

/*
** This R-way in-place partioning implementation uses two main ideas: key-indexed
** counting and moving in place, (1) we traverse the array to count the number 
** of the keys between 0 and R-1, and store the counting information in two auxiliary
** arrays, count[R] and node[R]. The positions where key i should be placed is between
** count[i] and node[i]. (2) Then we move the items in place according to the information.
** we take out an item array[j] between position count[i] and node[i] , name it as v, 
** if v==i, then it is the right place it belongs to and we put it back in array[j], if
** v!=i, it means v should be put somewhere else, i.e., position count[v], so we put v
** in array[count[v]], and squeeze out the original item in position array[count[v]],
** then we take the item squeezed out as v and repeat the process above, until v==i. Then
** we put v backward to the "hole" we made at first, i.e., array[j] so that a circle
** has been completed. Continue these operations for each key ranging from 0 to R-1, then
** every item should be in its place.
*/
void partition_in_place(item_t *array,int left,int right)
{
	int count[R];
	int node[R];
	int i,j;
	item_t t,v;
	
	/*
	** Key-indexed counting.
	*/
	for(i=0;i<R;i++){
		count[i]=0;
		node[i]=0;
	}

	for(i=left;i<=right;i++){
		count[array[i]+1]++;
	}

	for(i=1;i<R;i++){
		count[i]+=count[i-1];
	}

	for(i=0;i<R;i++){
		count[i]+=left;
	}

	for(i=0;i<R-1;i++){
		node[i]=count[i+1]-1;
	}
	node[R-1]=right;


	/*
	** Move the items in place using the "squeezing out" method.
	*/
	for(i=0;i<R;i++){
		for(j=count[i];j<=node[i];j++){
			copy_item(&v,&array[j]);

			while(v!=i){
				copy_item(&t,&array[count[v]]);
				copy_item(&array[count[v]++],&v);
				copy_item(&v,&t);
			}

			copy_item(&array[count[i]++],&v);
		}
	}
}
