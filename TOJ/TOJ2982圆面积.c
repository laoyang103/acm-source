#include <stdio.h>
#define PI 3.1415926
int main()
{
	double r;
	scanf("%lf",&r);
	printf("%.2lf %.2lf %.2lf\n",2*r,2*r*PI,r*r*PI);
	return 0;
}
