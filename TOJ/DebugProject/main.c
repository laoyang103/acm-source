//WA-º∆À„º∏∫Œ
#include <stdio.h>
#include <math.h>
double trangleArea(double x1,double y1,double x2,double y2,double x3,double y3)
{
	double a=fabs((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1));
	return a*0.5;
}
int main()
{
	double x1,y1,x2,y2,x3,y3;
	int n,i;
	double area;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)break;
		area=0;
		scanf("%lf%lf",&x1,&y1);
		scanf("%lf%lf",&x2,&y2);
		for(i=0;i<n-2;++i)
		{
			scanf("%lf%lf",&x3,&y3);
			area += trangleArea(x1,y1,x2,y2,x3,y3);
			x2=x3;
			y2=y3;
		}
		printf("%.1lf\n",area);
	}
	return 0;
}
/*
3 0 0 0 0 0 0
3 0 0 -1 -1 1 -1
4 -1 1 -1 -1 1 -1 1 1
6 -1 0 -2 0 -2 -1 -1 -1 0 -1 0 0
6 -2 0 -2 -1 -1 -1 0 -1 0 0 -1 0
*/
