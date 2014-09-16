#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int time;
	int value;
	double ratio;
}HomeWork;
HomeWork work[20];
int cmpare(const void* a,const void* b)
{
	return ((HomeWork*)a)->ratio > ((HomeWork*)b)->ratio;
}
int main()
{
	int M,N;
	int T,V;
	int i;
	while(scanf("%d%d",&m,&n))
	{
		if(m==0 && n==0)
			break;
		for(i=0;i<m;++i)
		{
			scanf("%d%d",&work[i].time,&work[i].value);
			work[i].ratio=(double)work[i].value/(double)work[i].time;
		}
		qsort(work,m,sizeof(HomeWork),compare);

	}
	return 0;
}