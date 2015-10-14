#include<stdlib.h>
#include"olist.h"
#include"item.h"

link_t new_node(item_t item)
{
	link_t x=malloc(sizeof(*x));
	x->next=NULL;
	x->out=NULL;
	copy_item(&(x->item),&item);
	
	return(x);
}

void insert_next(link_t x,link_t n)
{
	n->next=x->next;
	x->next=n;
}

link_t delete_next(link_t x)
{
	link_t t;	

	t=x->next;
	x->next=t->next;
	t->next=NULL;

	return(t);
}

link_t next_node(link_t x)
{
	return(x->next);
}

item_t item_node(link_t x)
{
	return(x->item);
}

void print_list(link_t head)
{
	link_t x;

	for(x=head;x!=NULL;x=x->next){
		print_item(x->item);
		putchar(' ');
	}
	putchar('\n');
}
