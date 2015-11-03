/*
** This program sorts N random elements using the nonrecursive Batcher's
** sort, and it applies to files of any size.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

void print_array(item_t *array,int n_elements);
void batcher_sort(item_t *array,int left,int right);


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
** This implementation of Batcher's odd-even sort correponds directly to the
** sorting network representation. It can be regarded as the bottom-up pass
** of merging a sequence of sorted files of length 2^k into a sequence of
** sorted files of length 2^(k+1). We use the full merging network, but include
** only those comparators that fall completely with subfiles. It divides into
** merging phases, indexed by the variable p, which do p-p merge operations. 
** The last phase, when p is N/2, is the N/2-N/2 Batcher's merge. The next-to-last
** phase, when p is N/4, is the N/4-N/4 odd-even merge with all comparators that
** cross N/2 eliminated; the third-to-last phase, when p is N/8, is the N/8-N/8
** merge with all comparators that cross any multiple of N/4 eliminated, and so
** forth. The whole process can be seen as a bottom-up method: we do 1-1 merge
** first, then 2-2 merge, then 4-4 merge, and so on, till the whole file is merged.
** Finally, it is glad to say that this sort works for any file size, but it is
** easy to understand when we assume the file size is a power of 2.
*/
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
						}
					}
				}
			}
		}
	}
}
