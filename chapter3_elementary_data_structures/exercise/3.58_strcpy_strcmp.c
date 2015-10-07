#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 100

char *string_copy(char *dest,char *src)
{
	char *a;
	int i;
	
	a=malloc((strlen(dest)+1)*sizeof(char));
	for(i=0;(a[i]=dest[i])!=0;i++);
	for(i=0;(a[i]=src[i])!=0;i++);

	return(a);
}

char *string_cat(char *dest,char *src)
{
	char *b;
	int i,j;

	b=malloc((strlen(dest)+strlen(src)+1)*sizeof(char));
	for(i=0;(b[i]=dest[i])!=0;i++);
	for(j=0;(b[i+j]=src[j])!=0;j++);

	return(b);
}

int main(void)
{
	char *dest="are you ok? ",*src="thank you.";
	char *a,*b;

	printf("dest:%s\n",dest);
	printf("src:%s\n",src);

	a=string_copy(dest,src);
	b=string_cat(dest,src);

	printf("a:%s\n",a);
	printf("b:%s\n",b);

	return(0);
}
