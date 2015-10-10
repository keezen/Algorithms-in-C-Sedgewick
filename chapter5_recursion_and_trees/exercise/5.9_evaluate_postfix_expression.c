#include<stdio.h>

char buf[100];
int ptr;

int eval(void)
{
	int x,i,j,right;

	for(;buf[ptr]==' ' || buf[ptr]=='\n' || buf[ptr]==0;ptr--)
		;

	if(buf[ptr]=='+'){
		ptr--;
		return(eval()+eval());
	}

	if(buf[ptr]=='*'){
		ptr--;
		return(eval()*eval());
	}

	for(x=0,i=0;buf[ptr]>='0' && buf[ptr]<='9' && ptr>=0;i++,ptr--){
		right=1;
		for(j=1;j<=i;j++)
			right*=10;
		
		x+=right*(buf[ptr]-'0');
	}

	return(x);		
}

int main(void)
{
	char ch;
	int i;
	FILE *fp;

	fp=fopen("evaluate_postfix_expression.txt","r");
	for(i=0;(ch=fgetc(fp)) != EOF;i++)
		buf[i]=ch;
	buf[i]=0;
	ptr=i;
	fclose(fp);

	for(i=0;buf[i]!=0;i++)
		putchar(buf[i]);

	printf("evalutation:%d\n",eval());

	return(0);
}
