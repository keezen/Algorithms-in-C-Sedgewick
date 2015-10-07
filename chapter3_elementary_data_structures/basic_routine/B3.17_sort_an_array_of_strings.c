#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Nmax 1000
#define Mmax 10000

char buf[Mmax],*array[Nmax];

int compare(void *i,void *j){
	return(strcmp(*(char **)i,*(char **)j));
}

int main(void)
{
	int N=0,M=0,i;
	FILE *fp;

	fp=fopen("sort_an_array_of_strings.txt","r");

	for(N=0;N<Nmax;N++){
		array[N]=&buf[M];
		if(fscanf(fp,"%s",array[N])==EOF)
			break;
		M+=strlen(array[N])+1;
	}
	
	fclose(fp);

	qsort(array,N,sizeof(char*),compare);

	for(i=0;i<N;i++)
		printf("array[%d]:%s\n",i,array[i]);

	return(0);
}
