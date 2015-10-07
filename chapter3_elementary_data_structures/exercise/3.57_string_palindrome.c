#include<stdio.h>
#include<string.h>

#define N 1000

int is_palindrome(char *string)
{
	int length=strlen(string),middle,i;
	printf("string[length-1]:%c\n",string[length-1]);

	for(middle=(length-1)/2,i=0;i<=middle && string[i]==string[length-1-i];i++);
	if(i==middle+1)
		return(1);
	
	return(0);
}

int main(void)
{
	char string[N],ch;
	int i;
	FILE *fp;

	fp=fopen("string_palindrome.txt","r");

	i=0;
	while((ch=fgetc(fp))!=EOF)
		if(ch!=' ' && ch!='\n')
			string[i++]=ch;
	string[i]=0;

	fclose(fp);

	
	if(is_palindrome(string))
		puts("The string is a palindrome.");
	else
		puts("The string is not a palindrome.");

	return(0);
}
