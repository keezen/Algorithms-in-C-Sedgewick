#ifndef RQ_H
#define RQ_H

#include"item.h"

void RQinit(int Nmax);
int RQempty(void);
int RQfull(void);
void RQput(item_t);
item_t RQget(void);
void RQdump(void);

#endif
