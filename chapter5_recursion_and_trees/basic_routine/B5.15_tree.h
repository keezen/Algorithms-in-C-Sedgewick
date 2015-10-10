#ifndef TREE_H
#define TREE_H

typedef char cont_t;
typedef struct node* link_t;
struct node{
        cont_t cont;
        link_t left,right;
};

link_t newNode(cont_t);

#endif
