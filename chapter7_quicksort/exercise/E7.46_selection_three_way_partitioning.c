#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

int partition(item_t *array,int left,int right);
void selection(item_t *array,int left,int right,int k);
void print_array(item_t *array,int n_elements);

int partition(item_t *array,int left,int right)
{
	item_t v=array[right];
	int i,j;

	i=left-1;
	j=right;
	while(1){
		while(compare_item(array[++i],v)<0)
			;
		while(compare_item(array[--j],v)>0){
			if(j==left)
				break;
		}
		if(i>=j)
			break;
		
		swap_item(&array[i],&array[j]);
	}

	swap_item(&array[i],&array[right]);

	return(i);
}

/*
** The selection function based on three-way partitioning.
*/
void selection(item_t *array,int left,int right,int k)
{
	int i,j,l,p,q;
	item_t v=array[right];

	if(right-left+1 <= 1){
		return;
	}

	/*
	** Three-way partitioning.
	*/
	i=left;
	j=right-1;
	p=left-1;
	q=right;
	while(1){
		for(;compare_item(array[i],v)<0;i++)
			;
		for(;compare_item(array[j],v)>0;j--)
			if(j==left)
				break;
		if(i>=j)
			break;

		swap_item(&array[i],&array[j]);
		if(compare_item(array[i],v)==0){
			swap_item(&array[i++],&array[++p]);	
		}
		if(compare_item(array[j],v)==0){
			swap_item(&array[j--],&array[--q]);
		}
	}

	if(i==j && compare_item(array[i],v)==0){
		swap_item(&array[i++],&array[++p]);	
	}	
	for(l=left;l<=p;l++,j--){
		swap_item(&array[l],&array[j]);
	}
	for(l=right;l>=q;l--,i++){
		swap_item(&array[l],&array[i]);
	}


	if(j<k && k<i){
		return;
	}
	if(k>=i){
		selection(array,i,right,k);
	}
	if(k<=j){
		selection(array,left,j,k);
	}
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

int main(int argc,char *argv[])
{
	int t=atoi(argv[1]);
	int N=atoi(argv[2]);
	item_t *array=malloc(N*sizeof(*array));
	int i;
	int k=4;

	srand((unsigned)time(NULL));

	for(i=0;i<N;i++){
		array[i]=rand()%t;
	}
	print_array(array,N);

	selection(array,0,N-1,k);
	print_array(array,N);
	putchar('\n');
	printf("the %dth smallest item is %d.\n",k+1,array[k]);

	free(array);

	return(0);
}
