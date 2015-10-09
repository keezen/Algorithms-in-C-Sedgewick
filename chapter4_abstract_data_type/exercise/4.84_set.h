#ifndef SET_H
#define SET_H

typedef struct set* set_t;
set_t setCrea(int M);
void setInsert(set_t s,int index);
set_t setUnion(set_t,set_t);
set_t setInter(set_t,set_t);
set_t setCompl(set_t);
set_t setDiff(set_t,set_t);
void setPrint(set_t);

#endif
