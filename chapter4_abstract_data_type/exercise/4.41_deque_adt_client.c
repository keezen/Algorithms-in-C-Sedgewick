#include<stdio.h>
#include<string.h>
#include"deque.h"

#define Nmax 100

int main(int argc,char *argv[])
{
	char ch,buf[Nmax+1];
	int i;

	strcpy(buf,argv[1]);
	dequeInit(Nmax);
	
	for(i=0;(ch=buf[i])!=0;i++){
		printf("%c\t",ch);

		if(ch>='A' && ch<='Z'){
			dequePut_begin(ch);
			putchar('\t');
		}
		if(ch>='a' && ch<='z'){
			dequePut_end(ch);
			putchar('\t');
		}
		if(ch=='+')
			printf("%c\t",dequeGet_begin());
		if(ch=='*')
			printf("%c\t",dequeGet_end());

		dequeDump();
		putchar('\n');
	}

	return(0);
}
