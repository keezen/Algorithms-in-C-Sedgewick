#ifndef STACK_H
#define STACK_H

#include"item.h"

void stackInit(int);
int stackEmpty(void);
void stackPush(item_t);
item_t stackPop(void);

#endif
