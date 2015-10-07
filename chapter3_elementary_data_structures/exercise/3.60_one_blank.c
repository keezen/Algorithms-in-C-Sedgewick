#include<stdio.h>
#include"dirlist.h"

link_t set_one_blank(link_t head)
{
	link_t x;
	
	for(x=Next(head);Item(x)!=0;x=Next(x)){
		while(Item(x)==' ' && Item(Next(x))==' ')
			freeNode(deleteNext(x));			
	}

	return(head);
}

void print_string(link_t head)
{
	link_t x;

	puts("the string:");
	for(x=Next(head);Item(x)!=0;x=Next(x))
		putchar(Item(x));
	putchar('\n');
}

int main(void)
{
	link_t head,x,t;
	item_t ch;
	int i,j;
	FILE *fp;

	fp=fopen("one_blank.txt","r");

	head=allocNode('\0');
	head->next=NULL;
	
	x=head;
	while((ch=fgetc(fp))!=EOF){
		t=allocNode(ch);
		insertNext(x,t);
		x=t;
	}
	t=allocNode(0);
	insertNext(x,t);
	x=t;

	fclose(fp);

	print_string(head);

	head=set_one_blank(head);
	print_string(head);
	
	return(0);
}
