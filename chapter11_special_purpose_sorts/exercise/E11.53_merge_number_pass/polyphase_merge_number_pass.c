/*
** This program computes the number of effective passes used for polyphase merge,
** given the number of devices P and the number of initial blocks.
*/
#include<stdio.h>
#include<stdlib.h>

/* The macro P indicates the number of devices. */
#define P 200


double polyphase_merge_pass(int n_block);


int main(int argc,char *argv[])
{
	double n_pass;
	int n_block=atoi(argv[1]);

	n_pass=polyphase_merge_pass(n_block);

	printf("the number of blocks: %d\n",n_block);
	printf("the number of passes: %.2f\n",n_pass);

	return(0);
}


/*
** This function computes the number of effective passes, given the number of
** initial blocks. The main idea of polyphase merge is merge-until-empty: (i) First
** we compute the number of runs on each device by working backward. To build the
** table of run distributions, we take the largest number in each row, make it zero,
** and add it to each of the other numbers to get the previous row. The main challenge
** in implementing a polyphase merge is to determine the initial run distributions.
** (ii) Given the run distribution, we can compute the relative lengths of the runs
** by working forward, keeping track of the run lengths produced by the merges. We can
** perform the indicated multiplications, sum the results, and divide by the number of
** initial runs to get the number of effective passes. By the way, if the number of
** runs is not a generalized Fibonacci number, we assume the existence of dummy runs to
** make the number of initial runs exactly what is needed for the table. For simplicity,
** we include the dummy runs in the cost calculation, which gives us an upper bound on
** the true cost.
*/
double polyphase_merge_pass(int n_block)
{
	int runs[P][2];
	int i,j,sum,max,min,zero;
	int process;

	for(i=0;i<P;i++){
		runs[i][0]=0;
		runs[i][1]=0;
	}
	runs[0][0]=1;
	

	/* Build the initial run distribution backward. */
	sum=1;
	while(sum<n_block){
		for(max=0,i=1;i<P;i++){
			if(runs[i][0]>runs[max][0]){
				max=i;
			}
		}

		for(i=0;i<P;i++){
			if(i==max){
				continue;
			}

			runs[i][0]+=runs[max][0];
		}
		runs[max][0]=0;

		for(sum=0,i=0;i<P;i++){
			sum+=runs[i][0];
		}
	}



	/* Compute the effective passes forward. */
	process=0;
	for(i=0;i<P;i++){
		if(runs[i][0]>0){
			runs[i][1]=1;
		}
	}	
	
	while(sum>1){
		for(i=0;i<P && runs[i][0]!=0;i++)
			;
		zero=i;

		for(min=0,i=0;i<P && runs[i][0]==0;i++)
			;
		min=i;
		for(;i<P;i++){
			if(0<runs[i][0] && runs[i][0]<runs[min][0]){
				min=i;
			}
		}


		for(i=0;i<P;i++){
			if(i==zero){
				continue;
			}	

			runs[zero][1]+=runs[i][1];
		}
		runs[min][1]=0;

		runs[zero][0]=runs[min][0];
		for(i=0;i<P;i++){
			if(i==zero){
				continue;		
			}
	
			runs[i][0]-=runs[zero][0];
			if(runs[i][0]==0){
				runs[i][1]=0;	
			}
		}

		
		for(sum=0,i=0;i<P;i++){
			sum+=runs[i][0];
		}
		process+=runs[zero][0]*runs[zero][1];
	}


	return((double)process/n_block);
}
