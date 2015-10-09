#ifndef UF_H
#define UF_H

typedef struct uf* uf_t;
uf_t UFinit(int N);
int UFfind(uf_t,int p,int q);
void UFunion(uf_t,int p,int q);
void UFdump(uf_t);

#endif

