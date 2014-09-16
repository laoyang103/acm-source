#include <stdio.h>
#include <math.h>
int main()
{
	int testCases;
	int array[5];
	int i;
	double average,s;
	scanf("%d",&testCases);
	while(testCases--)
	{
		average=0;
		s=0;
		for(i=0;i<5;++i)
		{
			scanf("%d",array+i);
			average+=array[i];
		}
		average/=5.0;
		for(i=0;i<5;++i)
		{
			s+=pow((array[i]-average),2);
		}
		s=sqrt(s/5.0);
		printf("%.3lf %.3lf\n",average,s);
	}
	return 0;
}
