#include<stdio.h>
#include"pqueue.h"
#include"item.h"

#define STRING_LENGTH 25

int main(void)
{
	item_t string[STRING_LENGTH+1]="PRIO*R**I*T*Y***QUE***U*E";
	int i;
	item_t operation,t;

	pqueue_init(STRING_LENGTH);

	for(i=0;i<STRING_LENGTH;i++){
		operation=string[i];
		printf("%c\t",operation);

		if(operation>='A' && operation<='Z'){
			pqueue_insert(operation);
			printf(" \t");
		}
		if(operation=='*'){
			t=pqueue_del_max();
			printf("%c\t",t);
		}

		pqueue_print();
	}

	return(0);
}
