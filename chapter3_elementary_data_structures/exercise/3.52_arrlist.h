#ifndef ARRLIST_H
#define ARRLIST_H

typedef int link_t;
link_t freelist;

void initNodes(int);
link_t newNode(int);
void freeNode(link_t);
void insertNext(link_t,link_t);
link_t deleteNext(link_t);
link_t Next(link_t);
int Item(link_t);

#endif
