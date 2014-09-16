#include <cstdio>
#include <cmath>
using namespace std;

double getJiaoY(double k,double b,double x)
{
	return k*x+b;
}
double getJiaoX(double k,double b,double y)
{
	return (y-b)/k;
}
bool isPointInRect(double p1,double p2,double p)
{
	if((p>=p1 && p<=p2)||(p>=p2 && p<=p1))
	{
		return true;
	}
	return false;
}
int main()
{
	int n;
	double x1,y1,x2,y2;
	double left,top,right,bottom;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",
				&x1,&y1,&x2,&y2,&left,&top,&right,&bottom);
		bool bJiao=false;
		if(y2 == y1)
		{//ÎÞÐ±ÂÊ
			if(isPointInRect(top,bottom,y1))
			{
				bJiao=true;
			}
		}
		else if(x1 == x2)//k=0
		{
			if(isPointInRect(left,right,x1))
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
