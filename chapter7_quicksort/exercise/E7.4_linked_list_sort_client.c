#include<stdio.h>
#include"list.h"
#include"item.h"

#define N 10

int compare_number=0;

int main(void)
{
	link_t head;
	int i;
	item_t new;

	head=init_list();

	printf("input item(name/number):\n");
	for(i=0;i<N;i++){
		scanf("%s %d",new.name,&new.number);

		new_node(new,head);
	}
	putchar('\n');
	print_list(head);
	putchar('\n');

	head=sort_list(head);
	print_list(head);
	putchar('\n');

	compare_number=1;
	head=sort_list(head);
	print_list(head);

	return(0);
}
