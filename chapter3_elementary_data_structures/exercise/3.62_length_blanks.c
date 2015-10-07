#include<stdio.h>
#include<string.h>

#define N 1000

int length_blanks(char *string)
{
	int length=0,count,i;

	for(i=0;string[i]!=0 && string[i]!=' ';i++);
	if(string[i]==0)
		return(0);		
	for(;string[i]==' ';length++,i++);
	
	while(string[i]!=0){
		for(;string[i]!=' ' && string[i+length]!=' ';i+=length)
			if(string[i]==0)
				break;
		if(string[i]==0)
				return(length);		
		
		if(string[i]!=' ')
			i+=length;

		for(;string[i]==' ';i--);
		for(i++,count=0;string[i]==' ';count++,i++);
		length=(count>length)?count:length;
	}

	return(length);
}

int main(void)
{
	char string[N]={0},ch;
	int i;
	FILE *fp;

	fp=fopen("length_blanks.txt","r");
	for(i=0;(ch=fgetc(fp))!=EOF;i++)
			string[i]=ch;
	string[i]=0;
	fclose(fp);

	printf("length of longest sequence of blanks:%d\n",length_blanks(string)); 

	return(0);
}
