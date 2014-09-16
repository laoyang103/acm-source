#include <stdio.h>
/*º∆À„x^(2n)/(2n)!
* x^(2n)/(2n)!=x^(2(n-1))/(2(n-1))! * x^2/(2n*(2n-1))
*/
double Cos(double angle,int n)
{
	int i;
	double r=1;
	double last=1;
	for(i=1;i<=n;++i)
	{
		last=last*angle*angle;
		last=last/(2*i);
		last=last/(2*i-1);
		if(i%2 == 0)
		{
			r+=last;
		}
		else r-=last;
	}
	return r;
}
int main()
{
	double angle;
	int n;
	scanf("%lf%d",&angle,&n);
	printf("%.4lf\n",Cos(angle,n));
	return 0;
}
