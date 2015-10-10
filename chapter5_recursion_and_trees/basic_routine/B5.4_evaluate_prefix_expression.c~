#include<stdio.h>

char buf[100];
int ptr=0;

int eval(void)
{
	int x;

	for(;buf[ptr]==' ';ptr++)
		;
	if(buf[ptr]=='+'){
		ptr++;
		return(eval()+eval());
	}
	if(buf[ptr]=='*'){
		ptr++;
		return(eval()*eval());
	}
	for(x=0;buf[ptr]>='0' && buf[ptr]<='9';ptr++)
		x=x*10+buf[ptr]-'0';
	return(x);		
}

int main(void)
{
	char ch;
	int i;
	FILE *fp;

	fp=fopen("evaluate_prefix_expression.txt","r");
	for(i=0;(ch=fgetc(fp)) != EOF;i++)
		buf[i]=ch;
	buf[i]=0;
	fclose(fp);

	printf("evalutation:%d\n",eval());

	return(0);
}
