#ifndef STRING_H
#define STRING_H

typedef struct string* str_t;
str_t stringCrea(int N,char *sour);
int stringLeng(str_t s);
int stringComp(str_t s1,str_t s2);
str_t stringConcat(str_t dest,str_t sour);
str_t stringCopy(str_t dest,str_t sour);
void stringPrint(str_t s);

#endif 
