#include <cstdio>
#include <cmath>
using namespace std;

bool fequal(double a,double b)//判断a是否等于b
{
	if(fabs(a-b) < 1e-6)return true;
	return false;
}
//获得斜率K和B
bool getKB(double x1,double y1,double x2,double y2,double &k,double &b)
{
	if(fequal(x2,x1)) return false;//无斜率
	k = (y2-y1)/(x2-x1);
	b = y1-k*x1;
	return true;
}
double getJiaoY(double k,double b,double x)
{
	return k*x+b;
}
double getJiaoX(double k,double b,double y)
{
	return (y-b)/k;
}
bool isPointInRect(double x1,double y1,double x2,double y2,double x,double y)
{
	if(x1>x2){double t=x1;x1=x2;x2=t;}
	if(y1>y2){double t=y1;y1=y2;y2=t;}
	if(x<x1 || x>x2 || y<y1 || y>y2)return false;
	return true;
}
int main()
{
	int n;
	double x1,y1,x2,y2;
	double left,top,right,bottom;
	bool bKExist;
	double k,b;
	double jx,jy;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",
				&x1,&y1,&x2,&y2,&left,&top,&right,&bottom);
		bool bJiao=false;
		bKExist=getKB(x1,y2,x2,y2,k,b);
		if(bKExist)
		{
			
		}
		else//斜率不存在
		{
			jx=x1;
			
		}
		if(y2 == y1)
		{
			if(y1 >= bottom && y1 <= top)
			{
				bJiao=true;
			}
		}
		else if(x1 == x2)//k=0
		{
			if(x1 >= left && x1 <= right)
			{
				bJiao=true;
			}
		}
		else
		{
			double k=(y2-y1)/(x1-x2);
			double b=y1-k*x1;
			double jx,jy;
			//判断线段和top线段是否相交
			if(isPointInRect(y1,y2,top))
			{
				jx=getJiaoX(k,b,top);
				if(isPointInRect(left,right,jx) && isPointInRect(x1,x2,jx))
				{
					bJiao=true;
					goto M_END;
				}
			}
			//判断线段是否和bottom线段相交
			if(isPointInRect(y1,y2,bottom))
			{
				jx=getJiaoX(k,b,bottom);
				if(isPointInRect(left,right,jx) && isPointInRect(x1,x2,jx))
				{
					bJiao=true;
					goto M_END;
				}
			}
			//判断线段是否和left线段相交
			if(isPointInRect(x1,x2,left))
			{
				jy=getJiaoY(k,b,left);
				if(isPointInRect(top,bottom,jy) && isPointInRect(y1,y2,jy))
				{
					bJiao=true;
					goto M_END;
				}
			}
			//判断线段是否和right线段相交
			if(isPointInRect(x1,x2,right))
			{
				jy=getJiaoY(k,b,right);
				if(isPointInRect(top,bottom,jy) && isPointInRect(y1,y2,jy))
				{
					bJiao=true;
				}
			}
		}
	M_END:
		if(bJiao)
		{
			printf("T\n");
		}
		else printf("F\n");
	}
    return 0;
}
