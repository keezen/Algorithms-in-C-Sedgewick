#include<stdio.h>
#include<string.h>

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

int evaluatePost(char *output)
{
	int x,i,j,right;

	for(;output[po]==' ' || output[po]=='\n' || output[po]==0;po--)
		;

	if(output[po]=='+'){
		po--;
		return(evaluatePost(output)+evaluatePost(output));
	}

	if(output[po]=='*'){
		po--;
		return(evaluatePost(output)*evaluatePost(output));
	}

	for(x=0,i=0;output[po]>='0' && output[po]<='9' && po>=0;i++,po--){
		right=1;
		for(j=1;j<=i;j++)
			right*=10;
		
		x+=right*(output[po]-'0');
	}

	return(x);		
}

void printExp(char *array)
{
	int i;
	for(i=0;array[i]!=0;i++)
		putchar(array[i]);
}

int evaluateInfix(char *input)
{
	convert(output,input);

	printExp(output);
	putchar('\n');

	po=strlen(output);
	evaluatePost(output);
}

int main(void)
{
	char ch;
	int i;
	FILE *fp;

	fp=fopen("evaluate_infix_expression.txt","r");
	for(i=0;(ch=fgetc(fp)) != EOF;i++){
		if(ch=='\n')
			continue;
		input[i]=ch;
	}
	input[i]=0;
	fclose(fp);

	printExp(input);
	putchar('\n');

	printf("evalutation:%d\n",evaluateInfix(input));

	return(0);
}
