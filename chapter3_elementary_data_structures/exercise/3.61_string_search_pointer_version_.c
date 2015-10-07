#include<stdio.h>

#define N 1000

int main(int argc,char *argv[])
{
	char *target=argv[1];
	char array[N],ch;
	int i,j;
	FILE *fp;

	fp=fopen("string_search_pointer_version.txt","r");

	for(i=0;i<N-1 && (ch=fgetc(fp))!=EOF;i++)
		*(array+i)=ch;
	*(array+i)='\0';

	for(i=0;*(array+i)!='\0';i++){
		for(j=0;*(target+j)!='\0' && *(target+j)==*(array+i+j);j++);
		if(*(target+j)=='\0')
			printf("the location:%d\n",i);
	}

	fclose(fp);
	
	return(0);
}
