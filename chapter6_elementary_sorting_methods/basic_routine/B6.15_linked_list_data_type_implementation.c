/*
** The implementation of the linked list data type.
*/
#include<stdio.h>
#include<stdlib.h>
#include"list.h"
#include"item.h"

struct NODE{
	item_t item;
	link_t next;
};

static link_t find_before_max(link_t head);
static link_t selection_sort_list(link_t head);

link_t init_list(void)
{
	link_t head;

	head=malloc(sizeof(*head));

	return(head);
}

link_t new_node(item_t item,link_t head)
{
	link_t new;

	new=malloc(sizeof(*new));
	copy_item(&new->item,&item);
	new->next=head->next;
	head->next=new;

	return(new);
}

void print_list(link_t head)
{
	link_t x;

	for(x=head->next;x!=NULL;x=x->next){
		print_item(x->item);
		putchar(' ');
	}
	putchar('\n');
}

static link_t find_before_max(link_t head)
{
	link_t before_max;
	link_t x;

	before_max=head;
	for(x=head;x->next != NULL;x=x->next){
		if(compare_item(x->next->item,before_max->next->item) > 0)
			before_max=x;
	}

	return(before_max);
}

/*
** Selection sort of a linked list. In this function, we main an
** input list, and an output list. While it is nonempty, we scan
** the input list to find the maximum remaining element, then remove
** that element from the input list and insert it at the ouput list.
*/
static link_t selection_sort_list(link_t head)
{
	link_t out,before_max;
	link_t max;
	
	out=NULL;
	while(head->next != NULL){
		before_max=find_before_max(head);
		max=before_max->next;
		before_max->next=max->next;

		max->next=out;
		out=max;
	}

	head->next=out;

	return(head);
}	

link_t sort_list(link_t head)
{
	return(selection_sort_list(head));
}
