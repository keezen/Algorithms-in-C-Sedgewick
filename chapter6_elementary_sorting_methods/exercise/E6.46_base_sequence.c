/*
** Derive the increment sequence from the base sequence,
** and test the runtime for it.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SEQUENCE 100
#define MAX_BASE 20

int sequences[MAX_SEQUENCE];
int n;

typedef int item_t;

int compare(void *a,void *b);
void swap(void *a,void *b);
void shell_sort(item_t *array,int left,int right);
void print_array(item_t *array,int n_elements);
void copy_array(item_t *dst,item_t *src,int n_elements);
int gcd(int a,int b);

int compare(void *a,void *b)
{
	return(*(int *)a - *(int *)b);
}

void swap(void *a,void *b)
{
	int t;

	t=*(int *)a;
	*(int *)a=*(int *)b;
	*(int *)b=t;
}

/*
** Shell sort the file.
*/
void shell_sort(item_t *array,int left,int right)
{
	int h;
	int i,j,k;
	item_t temp;

	for(k=n-1;k>=0;k--){
		h=sequences[k];

		for(i=left+h;i<=right;i++){
			temp=array[i];

			for(j=i-h;j>=left && compare(&array[j],&temp)>0;j-=h){
					array[j+h]=array[j];
			}

			array[j+h]=temp;
		}
	}	
}

void print_array(item_t *array,int n_elements)
{
	int i;

	for(i=0;i<n_elements;i++)
		printf("%d ",array[i]);
	putchar('\n');
}

void copy_array(item_t *dst,item_t *src,int n_elements)
{
	int i;

	for(i=0;i<n_elements;i++){
		dst[i]=src[i];
	}
}

int gcd(int a,int b)
{
	if(a%b==0){
		return(b);
	}

	return(gcd(b,a%b));
}

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	item_t *array=malloc(N*sizeof(*array));
	item_t *array_2=malloc(N*sizeof(*array_2));
	int i;
	int line;
	clock_t c1,c2;
	double sort_time;
	/*
	** Base sequence, you can adjust them to experiment runtimes
	** under different conditions.
	*/
	int base[MAX_BASE]={1,3,7,16,41,101};
	int n_base=6;

	srand((unsigned)time(NULL));

	for(i=0;i<N;i++){
		array[i]=rand()%N;
	}

	copy_array(array_2,array,N);

	sequences[0]=1;

	copy_array(array,array_2,N);
		
	/*
	** Construct increment sequences for the given base sequence.
	*/		
	for(n=1,line=2;line<n_base;line++){
		for(i=1;i<=line && sequences[n-1]<N;i++){
			if(i==1){
				sequences[n]=sequences[n-line+1]*base[line-1];		
			}else{
				sequences[n]=sequences[n-line]*base[line];				
			}

			n++;					
		}

		if(sequences[n-1]>=N){
			break;
		}
	}
	n--;

	c1=clock();
	shell_sort(array,0,N-1);
	c2=clock();

	sort_time=(double)(c2-c1)/CLOCKS_PER_SEC;

	print_array(sequences,n);
	printf("sort_time: %fs\n",sort_time);

	return(0);
}
