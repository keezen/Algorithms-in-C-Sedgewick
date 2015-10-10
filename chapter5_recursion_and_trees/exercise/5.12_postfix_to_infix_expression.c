#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Nmax 100

int pp;

void convert(char infix[],char postfix[])
{ 	
	char *s1,*s2,ch;
	int pi=0,i,j;

	for(;postfix[pp]==' ';pp--)
		;

	if((ch=postfix[pp])=='+' || ch=='*'){
		pp--;

		infix[pi++]='(';
		infix[pi++]=' ';

		s1=malloc(Nmax*sizeof(char));
		s2=malloc(Nmax*sizeof(char));
		for(i=0;i<Nmax;i++)
			s1[i]=s2[i]=0;	

		convert(s2,postfix);
		convert(s1,postfix);

		strcat(infix,s1),pi+=strlen(s1);
		
		infix[pi++]=' ';
		infix[pi++]=ch;
		infix[pi++]=' ';

		strcat(infix,s2),pi+=strlen(s2);

		infix[pi++]=' ';
		infix[pi++]=')';

		free(s1);
		free(s2);
		return;
	}

	for(i=0;postfix[pp]>='0' && postfix[pp]<='9' && pp>=0;i++,pp--)
			;
	for(j=1;j<=i;j++)
		infix[pi++]=postfix[pp+j];

	return;
}

int main(void)
{
	char postfix[Nmax],infix[Nmax]={0};
	char ch;
	int i;
	FILE *fp;

	fp=fopen("postfix_to_infix_expression.txt","r");
	i=0;
	while((ch=fgetc(fp)) != EOF){
		if(ch=='\n')
			continue;
		postfix[i]=ch;
		i++;
	}
	postfix[i]=0;
	pp=i-1;
	fclose(fp);

	printf("%s\n",postfix);

	convert(infix,postfix);

	printf("%s\n",infix);

	return(0);
}
