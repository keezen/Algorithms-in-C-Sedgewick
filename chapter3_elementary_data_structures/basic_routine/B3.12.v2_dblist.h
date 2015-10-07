#ifndef DBLIST_H
#define DBLIST_H

typedef int item_t;
typedef struct node* link_t;
struct node{
	item_t item;
	link_t prev;
	link_t next;
};

void initNodes(int);
link_t newNode(int);
void freeNode(link_t);
void insertNext(link_t,link_t);
link_t deleteNode(link_t);
link_t Prev(link_t);
link_t Next(link_t);
int Item(link_t);

#endif
