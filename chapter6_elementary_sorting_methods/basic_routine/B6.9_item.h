/*
** This item data type interface includes the definition
** for item_t, and the operations associated with it.
*/
#ifndef ITEM_H
#define ITEM_H

typedef int item_t;

item_t rand_item(void);
int scan_item(item_t *px);
void print_item(item_t x);
int compare_item(item_t a,item_t b);
void swap_item(item_t *pa,item_t *pb);

#endif
