#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"stack.h"
#include"item.h"

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

	printf("(%d,%d)\n",middle-left+1,right-middle);
	
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
** This nonrecursive mergesort implementation uses a stack to
** implement post-order visit. This function has the same effect
** as the top-down mergesort implementation.
*/
void merge_sort(item_t *array,int left,int right)
{
	int middle;
	int l,r,flag;

	if(right-left+1<=1){
		return;
	}

	stack_init(0);
	stack_push(left);
	stack_push(right);
	stack_push(0);

	/*
	** While the stack is not empty, pop an element. See whether
	** it is size 1 or less, if it is, let it go and pop next element,
	** if not, examine the flag part. If the flag is 1, it means that
	** this element has been visited and merge its two subfiles. If the
	** flag is 0, that element has not been visited, push it back to
	** the stack setting the flag 1, and then push its two subfiles to
	** the stack. Repeat the process above, when the stack is empty, the
	** array will be sorted.
	*/
	while(!stack_empty()){
		flag=stack_pop();
		r=stack_pop();
		l=stack_pop();

		if(r-l+1<=1){
			continue;
		}

		middle=(l+r)/2;
		if(flag==1){
			merge(array,l,middle,r);
		}else{
			stack_push(l);
			stack_push(r);
			stack_push(1);

			stack_push(middle+1);
			stack_push(r);
			stack_push(0);

			stack_push(l);
			stack_push(middle);
			stack_push(0);					
		}
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
