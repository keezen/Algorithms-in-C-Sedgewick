#ifndef DEQUE_H
#define DEQUE_H

#include"item.h"

void dequeInit(int Nmax);
int dequeEmpty(void);
void dequePut_begin(item_t);
void dequePut_end(item_t);
item_t dequeGet_begin(void);
item_t dequeGet_end(void);

#endif
