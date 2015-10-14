#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

#define min_int(a,b) (a)<(b)?(a):(b)
#define UNKNOWN -1

void merge(item_t *a,int left,int middle,int right);
void merge_sort(item_t *array,int left,int right);
void divide_top_down(int *aux,int left,int right);
void combine_bottom_up(item_t *array,int left,int right,int *aux);
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
** The divide_top_down function divides the elements top-down,
** and save the information about the dividing tree in the
** array aux.
** For example, if the original array has 4 elements, the initial
** aux array should be:
** 	0	1	2	3
** 	-1	-1	-1	-1
** we divide the 4 elements into two parts, so the array aux is:
** 	0	1	2	3
** 	-1	1	-1	-1
** aux[1]==1 means that aux[1] is the first-level dividng node of
** the dividing tree (you will see it clearer if you draw the recursive
** tree).
** Repeat the dividing process above, and finally you will get the
** array aux like this:
** 	0	1	2	3
** 	2	1	2	-1
** the element of aux means level in the dividing tree.
*/
void divide_top_down(int *aux,int left,int right)
{
	int middle,l,r;
	int level;

	for(level=1;aux[left]==UNKNOWN;level++){
		l=left;
		for(r=left;r<right;r++){
			if(aux[r]>=0 && aux[r]<level)
				break;
		}
	
		while(r<=right){
			if(l<r){
				middle=(l+r)/2;
				aux[middle]=level;
			}

			l=r+1;
			for(r=l;r<right;r++){
				if(aux[r]>=0 && aux[r]<level)
					break;
			}
		}
	}
}

/*
** You can merge the original array element using the diving information
** saved in aux. It is a practice of the bottom-up method. From the largest
** level(aux element) in the aux, merge the element until level 1 is merged.
** Then the original array is sorted.
** Take the same example, the aux array is:
** 	0	1	2	3
** 	2	1	2	-1
** The largest level is 2, so you merge elements from level 2, whose corresponding
** dividing elements are aux[0] and aux[2]. So at level 2, we merge a[0] and a[1](draw
** the tree to see it clearer), then merge a[2] and a[3].At level 1, dividing node
** is aux[1], we merge two subfiles, one subfile is (a[0],a[1]), the other
** is (a[2],a[3]). Now 4 elements have been merged completely.
*/
void combine_bottom_up(item_t *array,int left,int right,int *aux)
{
	int n=right-left+1;
	int l,r,m;
	int level;	

	for(level=aux[0];level>=1;level--){
		l=0;
		for(m=l;m<=n-1 && aux[m]!=level;m++)
			;
		for(r=m;r<n-1;r++){
			if(aux[r]>=0 && aux[r]<level)
				break;
		}

		while(r<=n-1){
			merge(array,l+left,m+left,r+left);

			l=r+1;
			for(m=l;m<=n-1 && aux[m]!=level;m++)
				;
			for(r=m;r<n-1;r++){
				if(aux[r]>=0 && aux[r]<level)
					break;
			}			
		}
	}	
}

/*
** This is a nonrecursive implementation of mergesort, which is 
** basically the bottom-up method. This function uses an auxiliary
** array, set up to contain the information about how the element 
** array is divided top-down. Then according to the array aux, merge
** the elements bottom-up.
*/
void merge_sort(item_t *array,int left,int right)
{
	int n=right-left+1;
	int *aux;
	int i,level;

	if(right-left+1<=1){
		return;
	}

	aux=malloc(n*sizeof(*aux));
	for(i=0;i<n;i++){
		aux[i]=UNKNOWN;
	}
	divide_top_down(aux,0,n-1);
//	print_array(aux,n);

	combine_bottom_up(array,left,right,aux);
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
