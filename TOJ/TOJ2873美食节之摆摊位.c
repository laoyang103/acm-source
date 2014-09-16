//WA 此题有些怪异
#include <stdio.h>
#include <math.h>
int getTan(double x,double y)
{
	double temp=(double)y/2.0;
	double th1=atan(temp/(double)x)*2.0;
	int r=(int)(6.0/th1);//内排能放的个数
//	double length=temp*(x+10)/x;
	int t=(x+10)/x;
	return r*t+r;
}
int main()
{
	int x,y;
	while(scanf("%d%d",&x,&y)==2)
	{
		printf("%d\n",getTan(x,y));
	}
	return 0;
}
