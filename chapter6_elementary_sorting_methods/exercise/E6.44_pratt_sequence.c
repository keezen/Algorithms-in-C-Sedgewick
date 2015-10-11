/*
** Calculate runtimes for different Pratt-like sequences based on h and k,
** and determine the lowest-runtime condition. 
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SEQUENCE 100

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
	int h,k,min_h,min_k;
	double lowest_time;
	double sort_time;

	srand((unsigned)time(NULL));

	for(i=0;i<N;i++){
		array[i]=rand()%N;
	}

	copy_array(array_2,array,N);

	/*
	** Calculate runtime for different couples of (h,k), which are relatively prime.
	*/
	lowest_time=100;
	min_h=0,min_k=0;
	sequences[0]=1;
	for(h=2;h<10;h++){
		for(k=h+1;k<10;k++){
			if(gcd(h,k)>1){
				continue;
			}

			copy_array(array,array_2,N);
			
			/*
			** Construct increment sequences for given h,k.
			*/		
			for(n=1,line=2;1;line++){
				for(i=1;i<=line && sequences[n-1]<N;i++){
					sequences[n]=sequences[n-line+1]*h;
					if(i==line){
						sequences[n]=sequences[n-line]*k;		
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
			if(sort_time<lowest_time){
				lowest_time=sort_time;
				min_h=h;
				min_k=k;	
			}
		}
	}

	printf("best h,k: %d,%d\n",min_h,min_k);
	printf("lowest_time: %fs\n",lowest_time);

	return(0);
}
