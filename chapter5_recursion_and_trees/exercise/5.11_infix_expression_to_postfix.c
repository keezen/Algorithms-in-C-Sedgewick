#include<stdio.h>

char input[100];
char output[100]={0};
int pi=0;
int po=0;

void convert(char *output,char *input)
{
	char ch;

	for(;input[pi]==')' || input[pi]==' ';pi++)
		;

	if(input[pi]=='('){
		pi++;
		convert(output,input);

		for(;input[pi]==')' || input[pi]==' ';pi++)
			;
		ch=input[pi++];

		convert(output,input);

		output[po++]=ch;
		output[po++]=' ';

		return;
	}

	for(;(ch=input[pi])>='0' && ch<='9';pi++)
		output[po++]=ch;
	output[po++]=' ';

	return;	
}

void printExp(char *array)
{
	int i;
	for(i=0;array[i]!=0;i++)
		putchar(array[i]);
}

int main(void)
{
	char ch;
	int i;
	FILE *fp;

	fp=fopen("infix_expression_to_postfix.txt","r");
	for(i=0;(ch=fgetc(fp)) != EOF;i++)
		input[i]=ch;
	input[i]=0;
	fclose(fp);

	printExp(input);
	putchar('\n');

	convert(output,input);

	printExp(output);
	putchar('\n');

	return(0);
}
