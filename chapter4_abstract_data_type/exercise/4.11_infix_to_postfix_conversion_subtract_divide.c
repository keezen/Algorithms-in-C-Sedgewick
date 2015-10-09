#include<stdio.h>
#include<string.h>
#include"item.h"
#include"stack.h"

int main(void)
{
	char ch;
	int i;
	FILE *fp;

	fp=fopen("infix_to_postfix_conversion.txt","r");
	
	stackInit(0);

	while((ch=fgetc(fp))!=EOF){
		if(ch>='0' && ch<='9')
			putchar(ch);
		if(ch=='+' || ch=='*' || ch=='-' || ch=='/')
			stackPush(ch);
		if(ch==')')
			putchar(stackPop());
	}

	fclose(fp);

	putchar('\n');

	return(0);
}
