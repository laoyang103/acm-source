#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c;
	double dlt;
	double m,n,x,y;
	scanf("%lf%lf%lf",&a,&b,&c);
	dlt=b*b-4*a*c;
	m=-b/(2*a);
	if(dlt>=1e-6)
	{
		n=sqrt(dlt)/(2*a);
		x=m+n;
		y=m-n;
		if(x<y)
		{
			m=x;
			x=y;
			y=m;
		}
		printf("%.2lf %.2lf\n",x,y);
	}
	else
	{
		n=fabs(sqrt(-dlt)/(2*a));
		printf("%.2lf+%.2lfi %.2lf-%.2lfi\n",m,n,m,n);
	}
	return 0;
}
