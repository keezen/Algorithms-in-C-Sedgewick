#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SEQUENCE 100
#define BUFFER_SIZE 1000

char buffer[BUFFER_SIZE];

typedef int item_t;

int compare(void *a,void *b);
void swap(void *a,void *b);
void shell_sort(item_t *array,int left,int right);
void print_array(item_t *array,int n_elements);

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

void shell_sort(item_t *array,int left,int right)
{
	int h;
	int i,j,k;
	item_t temp;
	char *p=buffer;
	int sequences[MAX_SEQUENCE];
	int n;

	n=0;
	while(*p != 0){
		sscanf(p,"%d",&sequences[n++]);

		for(;*p != ' ';p++){
			if(*p == 0)
				break;
		}
		for(;*p == ' ';p++)
			;
	}

	for(n--;sequences[n] >= right-left;n--)
		;

	for(;n>=0;n--){
		h=sequences[n];

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



int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	item_t *array=malloc(N*sizeof(*array));
	int i;
	FILE *input;
	clock_t c1,c2;

	input=fopen("add_delete_increment.dat","r");
	
	srand((unsigned)time(NULL));

	while(fgets(buffer,BUFFER_SIZE,input) != NULL){
		for(i=0;i<N;i++){
			array[i]=rand()%N;
		}
	
		c1=clock();
		shell_sort(array,0,N-1);
		c2=clock();
	
		printf("sequence: %s",buffer);
		printf("sort time: %fs\n\n",(double)(c2-c1)/CLOCKS_PER_SEC);
	}

	return(0);
}
