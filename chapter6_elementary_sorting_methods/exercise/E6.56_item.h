/*
** Interface of the record items data type, in which
** the item is the record structure itself, not the 
** pointer to it. It may work when the record is
** not so big, but it is a better choice to use pointers.
*/
#ifndef ITEM_H
#define ITEM_H

typedef struct RECORD{
	char name[30];
	int num;
} item_t;

item_t rand_item(void);
int scan_item(item_t *px);
void print_item(item_t x);
int compare_item(item_t a,item_t b);
void swap_item(item_t *pa,item_t *pb);

#endif
