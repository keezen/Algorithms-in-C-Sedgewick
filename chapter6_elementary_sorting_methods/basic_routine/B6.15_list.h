/*
** This linked list data type interface includes some
** functions associated with list operations, which consist
** of initializing, printing, and sorting the list. The 
** new_node function can add an item to the list pointed by
** head.
*/
#ifndef LIST_H
#define LIST_H

#include"item.h"

typedef struct NODE* link_t;

link_t init_list(void);
link_t new_node(item_t item,link_t head);
void print_list(link_t head);
link_t sort_list(link_t head);

#endif
