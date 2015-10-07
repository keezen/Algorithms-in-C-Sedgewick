#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Nmax 100
#define LENGTH 100

char *array[Nmax];

int compare(void *i,void *j){
	return(strcmp(*(char **)i,*(char **)j));
}

int main(void)
{
	int N=0,i;
	FILE *fp;

	fp=fopen("sort_an_array_of_strings.txt","r");

	for(N=0;N<Nmax;N++){
		array[N]=malloc((LENGTH+1)*sizeof(char));
		if(fscanf(fp,"%s",array[N])==EOF)
			break;
	}
	
	fclose(fp);

	qsort(array,N,sizeof(char*),compare);

	for(i=0;i<N;i++)
		printf("array[%d]:%s\n",i,array[i]);

	return(0);
}
