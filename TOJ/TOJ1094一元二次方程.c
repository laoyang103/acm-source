#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c;
	double x1,x2;
	scanf("%lf%lf%lf",&a,&b,&c);
	x1=(-b+sqrt(b*b-4*a*c))/(2*a);
	x2=(-b-sqrt(b*b-4*a*c))/(2*a);
	if (x1<x2)
	{
		a=x1;
		x1=x2;
		x2=a;
	}
	printf("%.2lf %.2lf\n",x1,x2);
	return 0;
}