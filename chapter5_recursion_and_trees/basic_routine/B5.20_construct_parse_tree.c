#include<stdio.h>
#include"tree.h"

char prefix[100];
int ptr=0;

link_t parse(char prefix[])
{
	link_t root,l,r;
	char ch;
	int x;

	for(;prefix[ptr]==' ';ptr++)
		;

	if((ch=prefix[ptr])=='+' || ch=='*'){
		ptr++;

		root=newNode(ch);
		l=parse(prefix);
		r=parse(prefix);
		leftAdd(root,l);
		rightAdd(root,r);
	
		return(root);
	}

	if((ch=prefix[ptr])>='0' && ch<='9'){
		ptr++;

		root=newNode(ch);

		return(root);
	}		
}

int main(void)
{
	link_t parse_tree;
	char ch;
	int i;
	FILE *fp;

	fp=fopen("construct_parse_tree.txt","r");
	for(i=0;(ch=fgetc(fp)) != EOF;i++){
		if(ch=='\n'){
			i--;
			continue;
		}			

		prefix[i]=ch;
	}
	prefix[i]=0;
	fclose(fp);

	for(i=0;prefix[i]!=0;i++)
		putchar(prefix[i]);
	putchar('\n');
	putchar('\n');

	parse_tree=parse(prefix);

	puts("parse tree:");
	treeShow(parse_tree);

	return(0);
}
