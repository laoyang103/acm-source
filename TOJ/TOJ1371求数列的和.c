#include <stdio.h>
#include <math.h>
double GetSqrt(double data,int m)
{
	double sum=0.0;
	while(m--)
	{
		sum+=data;
		data=sqrt(data);
	}
	return sum;
}
int main()
{
	double data;
	int m;
	while(scanf("%lf%d",&data,&m)==2)
	{
		printf("%.2lf\n",GetSqrt(data,m));
	}
	return 0;
}
