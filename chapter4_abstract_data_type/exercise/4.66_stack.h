#ifndef STACK_H
#define STACK_H

#include"item.h"

typedef struct stack* stack_t;
stack_t stackInit(int Nmax);
int stackEmpty(stack_t);
void stackPush(stack_t,item_t);
item_t stackPop(stack_t);

#endif 
