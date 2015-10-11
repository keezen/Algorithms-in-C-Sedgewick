/*
** Interface of the record items abstract data type, in which
** you can't see any implementation of the record items,
** so this is a generic interface.
*/
#ifndef ITEM_H
#define ITEM_H

typedef struct RECORD* item_t;

item_t rand_item(void);
int scan_item(item_t *px);
void print_item(item_t x);
int compare_item(item_t a,item_t b);
void swap_item(item_t *pa,item_t *pb);

#endif
