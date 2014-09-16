#include <stdio.h>
#include <math.h>
#define DOUBLE_ZEOR (1e-6)
//���б��k��ϵ��b
int getKB(double x1,double y1,double x2,double y2,double *k,double *b)
{
	if(fabs(x2-x1)<DOUBLE_ZEOR)return 0;//��б��
	*k = (y2-y1)/(x2-x1);
	*b = y1-(*k)*x1;
	return 1;
}
//���ֱ�߽���
int getJiao(double k1,double b1,double k2,double b2,double *jx,double *jy)
{
	if(fabs(k1-k2)<DOUBLE_ZEOR)return 0;//��ֱ��ƽ��
	*jx = (b2-b1)/(k1-k2);
	*jy = k1*(*jx)+b1;
	return 1;
}
int main()
{
	int t;
	double x1,y1,x2,y2;
	double x3,y3,x4,y4;
	double k1,b1;
	double k2,b2;
	double jx,jy;
	int isL1KExist;//ֱ��1��б���Ƿ����
	int isL2KExist;
	int isJiao;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",
			&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
		isL1KExist=getKB(x1,y1,x2,y2,&k1,&b1);
		isL2KExist=getKB(x3,y3,x4,y4,&k2,&b2);
		isJiao=0;
		if(isL1KExist==0 && isL2KExist==0)//б�ʶ������ڣ���ֱ��ƽ�У��޽���
		{
			isJiao=0;
		}
		else if(isL1KExist==0)//ֱ��1б�ʲ�����
		{
			isJiao=1;
			jx=x1;
			jy=k2*jx+b2;
		}
		else if(isL2KExist==0)//ֱ��2б�ʲ�����
		{
			isJiao=1;
			jx=x3;
			jy=k1*jx+b1;
		}
		else//б�ʶ�����
		{
			isJiao=getJiao(k1,b1,k2,b2,&jx,&jy);
		}
		if(isJiao==1)
		{
			printf("(%.2lf,%.2lf)\n",jx,jy);
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
/*
����+���
200
0 0 1 1
2 2 3 3
NO

0 0 1 1
0 1 1 0
(0.50,0.50)

-2 2 2 2
-2 -2 2 -2
NO

-2 2 -2 -2
2 2 2 -2
NO

-2 0 2 0
-2 0 2 0
NO

0 2 0 -2
0 2 0 -2
NO

2 2 -2 -2
4 2 0 -2
NO

-2 -2 2 2
-2 -2 2 2
NO

-2 2 2 2
0 4 0 -2
(0.00,2.00)

-2 0 2 0
2 2 -2 -2
(0.00,0.00)

0 2 0 -2
-2 -2 2 2
(0.00,0.00)

-2 2 2 -2
-2 -2 2 2
(0.00,0.00)

0 4 4 0
0 3 7 0
(1.75,2.25)

*/
