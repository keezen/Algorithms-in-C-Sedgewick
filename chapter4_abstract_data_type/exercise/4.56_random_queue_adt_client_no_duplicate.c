#include<stdio.h>
#include<string.h>
#include"rq.h"

#define Nmax 100
char buf[100];

int main(int argc,char *argv[])
{
	int i;
	char ch;

	strcpy(buf,argv[1]);
	RQinit(Nmax);

	for(i=0;(ch=buf[i])!=0;i++){
		printf("%c\t",ch);

		if(ch>='0' && ch <='9'){
			putchar('\t');
			RQput(ch-'0');
		}
		if(ch=='*')
			printf("%d\t",RQget());

		RQdump();
		putchar('\n');
	}

	return(0);
}
