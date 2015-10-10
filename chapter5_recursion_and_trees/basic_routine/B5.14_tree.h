#ifndef TREE_H
#define TREE_H

typedef char item_t;
typedef struct node* link_t;
struct node{
        item_t item;
        link_t left,right;
};

link_t newNode(item_t);

#endif
