#ifndef ITEM_H
#define ITEM_H

typedef struct ITEM{
	char name[20];
	int number;
}item_t;

void copy_item(item_t *a,item_t *b);
void print_item(item_t x);
int compare_item(item_t a,item_t b);

#endif
