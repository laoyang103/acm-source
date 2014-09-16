#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c;
	double area;
	while(scanf("%lf%lf%lf",&a,&b,&c)==3)
	{
		if(a+b<=c || a+c<=b || b+c<=a)printf("impossible\n");
		else
		{
			area=1.0/4.0*sqrt((a+b+c)*(a+b-c)*(a+c-b)*(b+c-a));
			printf("%.3lf\n",area);
		}
	}
	return 0;
}
