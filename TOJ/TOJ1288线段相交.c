#include <stdio.h>
#include <math.h>
#define DOUBLE_ZERO (1e-6)
//���б��K��B
int getKB(double x1,double y1,double x2,double y2,double *pK,double *pB)
{
	if(fabs(x1-x2)<DOUBLE_ZERO) return 0;//��б��
	*pK = (y2-y1)/(x2-x1);
	*pB = y1-(*pK)*x1;
	return 1;
}
//��ý���
int getJiao(double k1,double b1,double k2,double b2,double *pJX,double *pJY)
{
	if(fabs(k1-k2)<DOUBLE_ZERO)return 0;	//ֱ��ƽ��
	*pJX = (b2-b1)/(k1-k2);
	*pJY = k1*(*pJX)+b1;
	return 1;
}
//��ý��㣬k2������,y=k1x1+b1,x=b2.
int getJiaoEx(double k1,double b1,double b2,double *pJX,double *pJY)
{
	*pJX = b2;
	*pJY = k1*b2+b1;
	return 1;
}
int isPointInRect(double x1,double y1,double x2 ,double y2,double x,double y)
{
	double t;
	if(x1>x2){t=x1;x1=x2;x2=t;}
	if(y1>y2){t=y1;y1=y2;y2=t;}
	if(x<x1 || x>x2 || y<y1 || y>y2)return 0;
	return 1;
}
int main()
{
	int t;
	double px1,py1,px2,py2;//�߶�1������
	double qx1,qy1,qx2,qy2;//�߶�2������
	double k1,b1;//�߶�1��б�ʺ�b����
	double k2,b2;//�߶�2��б�ʺ�b����
	int isK1Exist,isK2Exist;//б���Ƿ����
	int isJiao;//�Ƿ��ཻ
	double jx,jy;//��������
	scanf("%d",&t);
	while(t--)
	{
		isJiao=0;
		scanf("%lf%lf%lf%lf",&px1,&py1,&px2,&py2);
		scanf("%lf%lf%lf%lf",&qx1,&qy1,&qx2,&qy2);
		//����߶ε�б�ʺ�B
		isK1Exist=getKB(px1,py1,px2,py2,&k1,&b1);
		isK2Exist=getKB(qx1,qy1,qx2,qy2,&k2,&b2);
		if(isK1Exist && isK2Exist)//��ֱ��б�ʶ�����
		{
			if(getJiao(k1,b1,k2,b2,&jx,&jy))//�����ֱ�߽���
			{
				//�ж������Ƿ������߶�����
				if(isPointInRect(px1,py1,px2,py2,jx,jy)
					&& isPointInRect(qx1,qy1,qx2,qy2,jx,jy))
				{
					isJiao=1;
				}
			}
			else//��ֱ��ƽ��
			{
				if(fabs(b1-b2)<DOUBLE_ZERO)//ֱ���Ƿ��غ�
				{
					//�ж��߶��Ƿ��н�����
					if(isPointInRect(px1,py1,px2,py2,qx1,qy1)
						|| isPointInRect(px1,py1,px2,py2,qx2,qy2)
						|| isPointInRect(qx1,qy1,qx2,qy2,px1,py1)
						|| isPointInRect(qx1,qy1,qx2,qy2,px2,py2))
					{
						isJiao=1;
					}
				}
			}
		}
		else if(isK1Exist)
		{
			//ֱ��2б�ʲ�����,x=qx2��
			b2=qx1;
			getJiaoEx(k1,b1,b2,&jx,&jy);
			if(isPointInRect(px1,py1,px2,py2,jx,jy)
				&& isPointInRect(qx1,qy1,qx2,qy2,jx,jy))
			{
				isJiao=1;
			}
		}
		else if(isK2Exist)
		{
			b1=px1;
			getJiaoEx(k2,b2,b1,&jx,&jy);
			if(isPointInRect(px1,py1,px2,py2,jx,jy)
				&& isPointInRect(qx1,qy1,qx2,qy2,jx,jy))
			{
				isJiao=1;
			}
		}
		else//��ֱ��б�ʶ�������
		{
			if(fabs(px1 - qx1) < DOUBLE_ZERO)//ֱ���غ�
			{
				//�ж��߶ε����˵��Ƿ���һ��������һ�߶���
				if(isPointInRect(px1,py1,px2,py2,qx1,qy1)
					|| isPointInRect(px1,py1,px2,py2,qx2,qy2)
					|| isPointInRect(qx1,qy1,qx2,qy2,px1,py1)
					|| isPointInRect(qx1,qy1,qx2,qy2,px2,py2))
				{
					isJiao=1;
				}
			}
		}
		if(isJiao)
		{
			puts("YES");
		}
		else puts("NO");
	}
	return 0;
}
/*
200
0 0 1 1
2 2 3 3

0 0 1 1
0 1 1 0

-2 2 2 2
-2 -2 2 -2

-2 2 -2 -2
2 2 2 -2

-2 0 2 0
-2 0 2 0

0 2 0 -2
0 2 0 -2

2 2 -2 -2
4 2 0 -2

-2 -2 2 2
-2 -2 2 2

-2 2 2 2
0 4 0 -2

-2 0 2 0
2 2 -2 -2

0 2 0 -2
-2 -2 2 2

-2 2 2 -2
-2 -2 2 2

0 4 4 0
0 3 7 0
*/
/*���ݼ����
200
0 0 1 1
2 2 3 3
NO

0 0 1 1
0 1 1 0
YES

-2 2 2 2
-2 -2 2 -2
NO

-2 2 -2 -2
2 2 2 -2
NO

-2 0 2 0
-2 0 2 0
YES

0 2 0 -2
0 2 0 -2
YES

2 2 -2 -2
4 2 0 -2
NO

-2 -2 2 2
-2 -2 2 2
YES

-2 2 2 2
0 4 0 -2
YES

-2 0 2 0
2 2 -2 -2
YES

0 2 0 -2
-2 -2 2 2
YES

-2 2 2 -2
-2 -2 2 2
YES

0 4 4 0
0 3 7 0
YES

*/
