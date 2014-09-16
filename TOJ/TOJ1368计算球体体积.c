#include <stdio.h>
#define PI 3.1415927
int main()
{
	double r;
	while(scanf("%lf",&r)==1)
	{
		printf("%.3lf\n",(4*PI*r*r*r)/3.0);
	}
	return 0;
}
