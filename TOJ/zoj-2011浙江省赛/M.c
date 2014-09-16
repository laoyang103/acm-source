#include <stdio.h>
#include <stdlib.h>
double array[510];
int cmp(const void *a,const void *b)
{
	return *(double*)a - *(double*)b;
}
int main()
{
	int t,n,i;
	double average;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;++i)
		{
			scanf("%lf",array+i);
		}
		qsort(array,n,sizeof(double),cmp);
		if(n%2 == 1)
		{
			printf("%.3lf\n",array[n/2]);
		}
		else
		{
			printf("%.3lf\n",(array[n/2]+array[n/2-1])/2.0);
		}
	}
	return 0;
}
