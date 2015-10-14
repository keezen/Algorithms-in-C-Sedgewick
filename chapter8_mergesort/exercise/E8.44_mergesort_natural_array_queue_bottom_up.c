#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"
#include"queue.h"

void merge(item_t *a,int left,int middle,int right);
void merge_sort(item_t *array,int left,int right);
void print_array(item_t *array,int n_elements);

void print_array(item_t *array,int n_elements)
{
	int i;

	for(i=0;i<n_elements;i++){
		print_item(array[i]);
		putchar(' ');
	}
	putchar('\n');
}

void merge(item_t *a,int left,int middle,int right)
{
	int n=right-left+1;
	item_t *aux=malloc(n*sizeof(*aux));
	int i,j,k;
	
	for(k=0,i=left;i<=middle;i++){
		aux[k++]=a[i];
	}
	for(i=right;i>middle;i--){
		aux[k++]=a[i];
	}

	for(i=0,j=n-1,k=left;k<=right;k++){
		if(compare_item(aux[i],aux[j])<0){
			a[k]=aux[i++];	
		}else{
			a[k]=aux[j--];	
		}
	}

	free(aux);
}

/*
** The implementation of array-based natural mergesort, using a queue.
** First we cut the file into order subfiles, put them in the queue,
** and then merge it until there is no file in the queue. So the
** whole file is sorted. This method is essentially a bottom-up way.
*/
void merge_sort(item_t *array,int left,int right)
{
	int l,r;
	int l2,r2;
	
	if(right-left+1<=1){
		return;
	}

	queue_init(0);

	/*
	** Cut the file into ordered subfiles, put them in the queue.
	*/
	for(l=left;l<=right;){
		for(r=l;r<right && compare_item(array[r],array[r+1])<=0;r++)
			;
		queue_put(l);
		queue_put(r);

		l=r+1;
	}
	
	/*
	** Every loop we get two subfiles from the queue, then merge them,
	** put the merged subfile back to the queue. Repeat this operation
	** until the queue is empty (you can also say until there is only one
	** subfile in the queue, then we get it, so the queue is empty). The
	** exception that we should pay attention to is that the first subfile
	** of the pair is the ending subfile (whose r is right). It is easy
	** to understand you can't merge the pair at this time because they
	** are not adjacent. So we discard the first subfile of the pair and
	** put it back to the queue, and then get another subfile to merge.
	*/
	while(1){
		l=queue_get();
		r=queue_get();
		if(queue_empty())
			break;
		l2=queue_get();
		r2=queue_get();

		/*
		** The exception that the first subfile (l,r) is
		** the ending subfile.
		*/
		if(r+1!=l2){
			queue_put(l);
			queue_put(r);
			l=l2;
			r=r2;
			l2=queue_get();
			r2=queue_get();
		}

		merge(array,l,r,r2);
		queue_put(l);
		queue_put(r2);
	}
}

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

	merge_sort(array,0,N-1);
	print_array(array,N);

	free(array);

	return(0);
}
