#ifndef ITEM_H
#define ITEM_H

typedef struct ITEM_NODE{
	char name[20];
	int num;
} item_t;

void swap_item(item_t *a,item_t *b);
void copy_item(item_t *a,item_t *b);
int compare_item(item_t a,item_t b);
void print_item(item_t x);

#endif
