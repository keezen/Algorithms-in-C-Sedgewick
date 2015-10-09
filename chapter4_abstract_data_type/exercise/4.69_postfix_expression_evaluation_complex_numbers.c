#include<stdio.h>
#include<string.h>
#include"stack.h"
#include"complex.h"

char string[100];

int main(void)
{
	int i,N;
	char ch;
	int re,im;
	complex_t z;
	FILE *fp;

	fp=fopen("postfix_expression_evaluation_complex_numbers.txt","r");
	for(i=0;(ch=fgetc(fp)) != EOF;i++)
		string[i]=ch;
	string[i]=0;
	fclose(fp);

	N=strlen(string);
	stackInit(N);

	for(i=1;i<N;i++){
		if(string[i]=='i'){
			re=string[i-3]-'0';
			im=string[i-1]-'0';
			if(string[i-2]=='-')
				im=-im;

			z=complexInit(re,im);
			stackPush(z);	
		}
		if(string[i]=='+' && string[i-1]==' ')
			stackPush(complexAdd(stackPop(),stackPop()));
		if(string[i]=='*')
			stackPush(complexMult(stackPop(),stackPop()));
	}

	z=stackPop();
	printf("the evalution:%d+%di\n",(int)Re(z),(int)Im(z));

	return(0);
}
