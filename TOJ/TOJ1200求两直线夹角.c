#include <stdio.h>
#include <math.h>
#define DOUBLE_ZERO (1e-6)
#define PI 3.14159265
int getK(double x1,double y1,double x2,double y2,double *pk)
{
	if(fabs(x1-x2)<DOUBLE_ZERO)return 0;//无斜率
	*pk=(y2-y1)/(x2-x1);
	return 1;
}
/*已知斜率求夹角 tan(o)=|(k1-k2)/(1+k1*k2)|
*/
double getJiaJiao(double k1,double k2)
{
	return atan(fabs((k1-k2)/(1+k1*k2)));
}
int main()
{
	double x1,y1,x2,y2;
	double tx1,ty1,tx2,ty2;
	double k1,tk2;
	double isK1Exist,isTK2Exist;
	int t;
	double angle;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",
				&x1,&y1,&x2,&y2,&tx1,&ty1,&tx2,&ty2);
		isK1Exist=getK(x1,y1,x2,y2,&k1);
		isTK2Exist=getK(tx1,ty1,tx2,ty2,&tk2);
		if(isK1Exist==1 && isTK2Exist==1)
		{
			angle=getJiaJiao(k1,tk2);
		}
		else if(isK1Exist==1)//直线1斜率存在
		{
			angle=atan(fabs((x2-x1)/(y2-y1)));
		}//若一条直线的斜率不存在，则可看为一条直线与y轴的夹角
		else if(isTK2Exist==1)//直线2斜率存在
		{
			angle=atan(fabs((tx2-tx1)/(ty2-ty1)));
		}
		else angle=0.0;
		angle*=180.0/PI;
		printf("%.1lf\n",angle);
	}
	return 0;
}
/*
100
0 0 1 1 0 0 1 1
0 0 1 1 0 1 1 2
0 0 0 1 1 0 1 1
0 1 1 4 0 1 -1 4
0 0 0 1 0 1 1 4
0 0 0 1 0 1 -1 4
*/
