#include<stdio.h>

#define N 1000
#define M 100

int search_string(char *array,char *target)
{
	int i,j;

	for(i=0;array[i]!='\0';i++){
		for(j=0;target[j]!='\0' && target[j]==array[i+j];j++);
			if(target[j]=='\0')
				return(i);
	}

	return(-1);
}

void find_word(char *array)
{
	char target[M][M]={0};
	char ch;
	int i=0,j;

	puts("please type the words:");
	while((ch=getchar())!=EOF){
		if(ch!=' ')
			target[i][j++]=ch;
		else{
			target[i++][j]=0;
			j=0;
		}
	}
	putchar('\n');

	for(i=0;target[i][0]!=0;i++)
		if(search_string(array,target[i])!=-1)
			printf("substring:%s\n",target[i]);		
	
}

int main(void)
{
	char array[N],ch,*temp;
	int i;
	FILE *fp;

	fp=fopen("substring_word.txt","r");

	for(i=0;i<N-1 && (ch=fgetc(fp))!=EOF;i++)
		array[i]=ch;
	array[i]='\0';

	find_word(array);
	
	return(0);
}
