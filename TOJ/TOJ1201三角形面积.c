#include <stdio.h>
#include <math.h>
int main()
{
	double a,b,c,area,p;
	while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF)
	{
		p=(a+b+c)/2.0;
		area=sqrt(p*(p-a)*(p-b)*(p-c));
		printf("%.3lf\n",area);
	}
	return 0;
}
