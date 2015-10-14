#include<stdio.h>
#include<stdlib.h>
#include"list.h"
#include"item.h"

link_t merge_list(link_t heada,link_t headb);

/*
** This function merges the list pointed to by heada with the list
** pointed to by headb, with the help of an auxiliary pointer c. The
** merge will be stable, if the headb list is considered to follow the
** heada list.
*/
link_t merge_list(link_t heada,link_t headb)
{
	link_t c,t;
	link_t head=malloc(sizeof(*head));
	
	c=head;
	c->next=NULL;
	while(heada!=NULL && headb!=NULL){
		if(compare_item(heada->item,headb->item)<=0){
			t=heada;
			heada=t->next;
			t->next=NULL;

			c->next=t;
			c=t;
		}else{
			t=headb;
			headb=t->next;
			t->next=NULL;

			c->next=t;
			c=t;
		}
	}

	if(heada==NULL){
		c->next=headb;
	}else{
		c->next=heada;
	}

	t=head;
	head=head->next;
	free(t);

	return(head);
}

int main(void)
{
	link_t heada,headb,headc;
	link_t t;
	int i;

	heada=new_node(1);
	for(i=5;i>=2;i--){
		t=new_node(i);
		insert_next(heada,t);
	}

	headb=new_node(6);
	for(i=10;i>=7;i--){
		t=new_node(i);
		insert_next(headb,t);
	}

	print_list(heada);
	print_list(headb);


	headc=merge_list(heada,headb);
	print_list(headc);

	return(0);
}
