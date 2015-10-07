#include<stdio.h>

#define N 1000

void print_character_frequency(char *string)
{
	char character[N]={0},ch;
	int frequency[N]={0},i,j;

	for(i=0;(ch=string[i])!='\0';i++){
		for(j=0;character[j]!='\0'&& ch!=character[j];j++);
		if(character[j]==0)
			frequency[j]++,character[j]=ch;
		else
			frequency[j]++;
	}

	for(i=0;character[i]!=0;i++){
		printf("character:%c\tfrequency:%d\n",character[i],frequency[i]);
	}
}

int main(int argc,char *argv[])
{
	char string[N],ch;
	int i;
	FILE *fp;

	fp=fopen("character_frequency.txt","r");

	for(i=0;(ch=fgetc(fp))!=EOF;i++)
		string[i]=ch;
	string[i]=0;

	fclose(fp);
	
	print_character_frequency(string);

	return(0);
}

