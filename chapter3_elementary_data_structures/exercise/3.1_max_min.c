#include<stdio.h>
#include<limits.h>
#include<float.h>

int main(void)
{
	printf("sizeof(int):%lu\n",sizeof(int));
	printf("sizeof(long):%lu\n",sizeof(long));
	printf("sizeof(short):%lu\n",sizeof(short));
	printf("sizeof(float):%lu\n",sizeof(float));
	printf("sizeof(double):%lu\n\n",sizeof(double));

	printf("max_int:%d\n",INT_MAX);
	printf("max_long:%ld\n",LONG_MAX);
	printf("max_short:%d\n",SHRT_MAX);
	printf("max_float:%f\n",FLT_MAX);
	printf("max_double:%f\n\n",DBL_MAX);

	printf("min_int:%d\n",INT_MIN);
	printf("min_long:%ld\n",LONG_MIN);
	printf("min_short:%d\n",SHRT_MIN);
	printf("min_float:%f\n",FLT_MIN);
	printf("min_double:%f\n\n",DBL_MIN);

	return(0);
}
