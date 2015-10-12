#ifndef LIST_H
#define LIST_H

#include"item.h"

typedef struct NODE* link_t;

link_t init_list(void);
link_t new_node(item_t item,link_t head);
void print_list(link_t head);
link_t sort_list(link_t head);

#endif
