#include <stdio.h>
#include <stdlib.h>
typedef struct Paper
{
	int time;
	int value;
	double percent;
}Paper;
Paper pap[20];
int cmp(const void *a,const void *b)
{
	Paper *pa=(Paper*)a;
	Paper *pb=(Paper*)b;
	double t=pa->percent - pb->percent;
	if(t < -(1e-6))return -1;
	else if(t > 1e-6)return 1;
	else return 0;
}
int main()
{
	int n,rt;
	int i;
	int totalT;
	double value;
	while(1)
	{
		totalT=0;
		value=0;
		scanf("%d%d",&n,&rt);
		if(n==0 && rt==0)break;
		for(i=0;i<n;++i)
		{
			scanf("%d%d",&pap[i].time,&pap[i].value);
			pap[i].percent=pap[i].value/pap[i].time;
		}
		qsort(pap,n,sizeof(Paper),cmp);
		for(i=0;i<n;++i)
		{
			if(totalT+pap[i].time <= rt)
			{
				totalT+=pap[i].time;
				value+=pap[i].value;
			}
			else
			{
				value+=(rt-totalT)*pap[i].percent;
				break;
			}
		}
		printf("%.2lf\n",value);
	}
	return 0;
}
