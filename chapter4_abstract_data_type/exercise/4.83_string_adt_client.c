#include<stdio.h>
#include"string.h"

int main(void)
{
	str_t str1,str2;

	str1=stringCrea(20,"hello ");
	str2=stringCrea(20,"world");
	stringPrint(str1);
	putchar('\n');
	printf("stringLeng:%d\n",stringLeng(str1));

	switch(stringComp(str1,str2)){
		case 0:puts("str1 = str2");break;
		case 1:puts("str1 > str2");break;
		case -1:puts("str1 < str2");break;
	}

	stringConcat(str1,str2);
	stringPrint(str1);
	putchar('\n');

	stringCopy(str1,str2);
	stringPrint(str1);
	putchar('\n');

	return(0);
}
