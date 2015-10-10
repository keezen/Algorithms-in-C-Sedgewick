#ifndef TREE_H
#define TREE_H

typedef char cont_t;

typedef struct node* link_t;

link_t newNode(cont_t);
link_t Left(link_t);
link_t Right(link_t);
cont_t Cont(link_t);
void leftAdd(link_t root,link_t left);
void rightAdd(link_t root,link_t right);
void treeShow(link_t t);

#endif
