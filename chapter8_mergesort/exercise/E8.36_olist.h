#ifndef OLIST_H
#define OLIST_H

#include"item.h"

typedef struct NODE* link_t;
struct NODE{
	item_t item;
	link_t next;
	link_t out;
};

link_t new_node(item_t item);
void insert_next(link_t x,link_t n);
link_t delete_next(link_t x);
link_t next_node(link_t x);
item_t item_node(link_t x);
void print_list(link_t head);

#endif
