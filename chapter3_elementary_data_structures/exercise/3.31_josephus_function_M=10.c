#include<stdio.h>
#include<stdlib.h>

typedef struct node* link_t;

struct node{
	int item;
	link_t next;
};

int main(void)
{
	int N,M=10,josephus_value;
	int i;
	struct node *x,*temp;
	FILE *fp;

	fp=fopen("josephus_function_M=10.dat","w");

	for(N=2;N<=1000;N++){
		x=malloc(sizeof(struct node));
		x->item=1;
		x->next=x;	
		for(i=2;i<=N;i++){
			temp=x;
			x=malloc(sizeof(struct node));
			x->item=i;
	
			x->next=temp->next;
			temp->next=x;
		}
	
		while(x->next!=x){
			for(i=1;i<M;i++)
				x=x->next;

			x->next=x->next->next;
		}
		josephus_value=x->item;

		fprintf(fp,"%4d\t%4d\n",N,josephus_value);
	}

	fclose(fp);

	return(0);
}
