#include <stdio.h>
#include <math.h>
int main()
{
	double input;
	while(scanf("%lf",&input)==1)
	{
		printf("%.2lf\n",fabs(input));
	}
	return 0;
}
