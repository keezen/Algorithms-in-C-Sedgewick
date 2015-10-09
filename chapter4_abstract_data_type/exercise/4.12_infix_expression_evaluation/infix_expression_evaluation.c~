#include<stdio.h>
#include<math.h>
#include<string.h>
#include"stack1.h"
#include"stack2.h"

#define Nmax 1000

char postfix[Nmax]={0};

void convert_infix_to_postfix(FILE *fp)
{
	char ch;
	int i=0;

	stackInit1(0);

	while((ch=fgetc(fp))!=EOF){
		if(ch>='0' && ch<='9')
			postfix[i++]=ch;
		if(ch=='+' || ch=='*' || ch=='-' || ch=='/' || ch=='$' || ch=='~')
			stackPush1(ch);
		if(ch==')')
			postfix[i++]=stackPop1();
	}
	postfix[i]='\0';
}

double postfix_expression_evaluation()
{
	int N=strlen(postfix),i;

	stackInit2(N);

	for(i=0;i<N;i++){
		if(postfix[i]>='0' && postfix[i]<='9')
			stackPush2((double)(postfix[i]-'0'));
		if(postfix[i]=='+')
			stackPush2(stackPop2()+stackPop2());
		if(postfix[i]=='*')
			stackPush2(stackPop2()*stackPop2());
		if(postfix[i]=='-'){
			double y=stackPop2();
			double x=stackPop2();
			stackPush2(x-y);		
		}
		if(postfix[i]=='/'){
			double y=stackPop2();
			double x=stackPop2();
			stackPush2(x/y);		
		}
		if(postfix[i]=='$')
			stackPush2(sqrt(stackPop2()));
		if(postfix[i]=='~')
			stackPush2(-stackPop2());
	}

	return(stackPop2());
}

int main(void)
{
	double result;
	int i;
	FILE *fp;

	fp=fopen("infix_expression_evaluation.txt","r");

	convert_infix_to_postfix(fp);

	fclose(fp);

	for(i=0;postfix[i]!=0;i++)
		putchar(postfix[i]);
	putchar('\n');

	result=postfix_expression_evaluation();
	printf("the evaluation:%f\n",result);

	return(0);
}
