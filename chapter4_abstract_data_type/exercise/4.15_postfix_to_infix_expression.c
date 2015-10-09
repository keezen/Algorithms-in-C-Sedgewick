#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"

#define Nmax 100

void convert(char infix[],char postfix[])
{
	int i,j;
	char *str1,*str2,*str,ch;

	i=0;
	while(postfix[i]!=0){
		for(;postfix[i]==' ';i++)
			;
	
		if((ch=postfix[i])=='+' || ch=='*'){
			str2=stackPop();
			str1=stackPop();

			str=malloc(Nmax*sizeof(char));
			j=0;
			str[j++]='(';
			str[j++]=' ';
			strcpy(str+j,str1),j+=strlen(str1);
			str[j++]=' ';
			str[j++]=ch;
			str[j++]=' ';
			strcpy(str+j,str2),j+=strlen(str2);
			str[j++]=' ';
			str[j++]=')';
			str[j++]=0;

			free(str1);
			free(str2);
			stackPush(str);

			i++;
			continue;	
		}
			
		if((ch=postfix[i])>='0' && ch<='9'){
			str=malloc(Nmax*sizeof(char));
			for(j=0;(ch=postfix[i])>='0' && ch<='9';i++)
				str[j++]=ch;
			str[j++]=0;

			stackPush(str);	
		}
	}

	strcpy(infix,(str=stackPop()));
	free(str);
}

int main(void)
{
	char postfix[Nmax],infix[Nmax];
	char ch;
	int i;
	FILE *fp;

	stackInit(Nmax);

	fp=fopen("postfix_to_infix_expression.txt","r");
	i=0;
	while((ch=fgetc(fp)) != EOF){
		if(ch=='\n')
			continue;
		postfix[i]=ch;
		i++;
	}
	postfix[i]=0;
	fclose(fp);

	printf("%s\n",postfix);

	convert(infix,postfix);

	printf("%s\n",infix);

	return(0);
}
