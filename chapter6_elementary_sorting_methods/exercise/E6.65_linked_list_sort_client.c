#include"list.h"

int main(void)
{
	link_t head;
	int i;

	head=init_list();

	for(i=0;i<10;i++)
		new_node(i,head);
	print_list(head);

	head=sort_list(head);
	print_list(head);

	return(0);
}
