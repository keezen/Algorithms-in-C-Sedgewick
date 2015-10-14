#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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

/*
** An abstract in-place merge that uses extra space equal to
** the size of the smaller of the two arrays to be merged.
*/
void merge(item_t *a,int left,int middle,int right)
{
	int m=middle-left+1;
	int n=right-middle;
	item_t *aux;
	int i,j,k;

	/*
	** Dynamically allocate the auxiliary array whose size is
	** equal to the size of the smaller of the two subfiles.
	** Then copy the smaller subfile to the array aux in reverse
	** order, move another subfile backward to the end of the array a. 
	*/
	if(m<=n){
		aux=malloc(m*sizeof(*aux));
		for(k=0;k<m;k++){
			aux[k]=a[middle-k];
		}
		i=m-1;
		j=middle+1;
	}else{
		aux=malloc(n*sizeof(*aux));
		for(k=0;k<n;k++){
			aux[k]=a[right-k];
		}
		for(j=right,k=middle;k>=left;k--){
			a[j--]=a[k];
		}
		i=n-1;
		j=right+1-m;
	}

	/*
	** Merge the two subfiles, leaving the result in array a.
	*/
	for(k=left;k<=right;k++){
		if(i==-1){
			a[k]=a[j++];
			continue;	
		}
		if(j==right+1){
			a[k]=aux[i--];
			continue;
		}

		if(compare_item(aux[i],a[j])<0){
			a[k]=aux[i--];
		}else{
			a[k]=a[j++];
		}
	}

	free(aux);
}

void merge_sort(item_t *array,int left,int right)
{
	int middle=(left+right)/2;	

	if(right-left+1<=1){
		return;
	}

	merge_sort(array,left,middle);
	merge_sort(array,middle+1,right);
	merge(array,left,middle,right);
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
