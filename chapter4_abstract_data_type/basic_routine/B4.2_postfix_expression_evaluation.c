#include<stdio.h>
#include<string.h>
#include"stack.h"

int main(int argc,char *argv[])
{
	char *string=argv[1];
	int N=strlen(string),i;

	stackInit(N);

	for(i=0;i<N;i++){
		if(string[i]>='0' && string[i]<='9')
			stackPush(string[i]-'0');
		if(string[i]=='+')
			stackPush(stackPop()+stackPop());
		if(string[i]=='*')
			stackPush(stackPop()*stackPop());
	}

	printf("the evalution:%d\n",stackPop());

	return(0);
}
