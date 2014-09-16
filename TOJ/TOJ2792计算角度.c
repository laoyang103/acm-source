#include <stdio.h>
#include <math.h>
double getAngle(double d)
{
	return acos(d)*180.0/3.14159;
}
int main()
{
	double in;
	while(scanf("%lf",&in)!=EOF)
	{
		if(in<-1.0 || in>1.0)puts("error");
		else printf("%0.1lf\n",getAngle(in));
	}
	return 0;
}
