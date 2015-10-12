#include<stdio.h>
#include<stdlib.h>
#include"list.h"
#include"item.h"

struct NODE{
	item_t item;
	link_t next;
};

static link_t quick_sort_list(link_t head);

link_t init_list(void)
{
	link_t head;

	head=malloc(sizeof(*head));
	head->next=NULL;

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

static link_t quick_sort_list(link_t head)
{
	link_t less_head,less_tail;
	link_t more_head,more_tail;
	link_t current,x;

	if(head->next==NULL){
		return(head);
	}

	current=head->next;
	head->next=current->next;

	less_head=malloc(sizeof(*less_head));
	less_head->next=NULL,less_tail=less_head;
	more_head=malloc(sizeof(*more_head));
	more_head->next=NULL,more_tail=more_head;

	while((x=head->next) != NULL){	
		head->next=x->next;
		x->next=NULL;

		if(compare_item(x->item,current->item)<0){			
				less_tail->next=x;
				less_tail=x;
		}else{				
				more_tail->next=x;
				more_tail=x;
		}
	}

	less_head=quick_sort_list(less_head);
	more_head=quick_sort_list(more_head);
	for(less_tail=less_head;less_tail->next != NULL;less_tail=less_tail->next)
		;
	for(more_tail=more_head;more_tail->next != NULL;more_tail=more_tail->next)
		;

	less_tail->next=current;
	current->next=more_head->next;
	head->next=less_head->next;

	free(less_head);
	free(more_head);	

	return(head);
}	

link_t sort_list(link_t head)
{
	return(quick_sort_list(head));
}
