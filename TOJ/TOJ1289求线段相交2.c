//δͨ��
#include <stdio.h>
#include <math.h>
#define MIN(x,y) (x < y ? x : y)
#define MAX(x,y) (x > y ? x : y)
typedef struct
{
    double x,y;
} Point;
int lineintersect(Point p1,Point p2,Point p3,Point p4)
{
    Point tp1,tp2,tp3;
    //�ж϶˵��غ�
    if((p1.x==p3.x&&p1.y==p3.y)
		||(p1.x==p4.x&&p1.y==p4.y)
		||(p2.x==p3.x&&p2.y==p3.y)
		||(p2.x==p4.x&&p2.y==p4.y))
        return 2;
// �����ų�����,�ж�p1��p2�Ƿ�λ��p3����p4�����ߣ�
//��������ཻ������һ�����ཻ
    if((MIN(p1.x,p2.x)<=p3.x
		&&p3.x<=MAX(p1.x,p2.x)
		&&MIN(p1.y,p2.y)<=p3.y
		&&p3.y<=MAX(p1.y,p2.y))
	||(MIN(p1.x,p2.x)<=p4.x
		&&p4.x<=MAX(p1.x,p2.x)
		&&MIN(p1.y,p2.y)<=p4.y
		&&p4.y<=MAX(p1.y,p2.y)))
        ;
    else return 0;
// ��������
    tp1.x=p1.x-p3.x;
    tp1.y=p1.y-p3.y;
    tp2.x=p4.x-p3.x;
    tp2.y=p4.y-p3.y;
    tp3.x=p2.x-p3.x;
    tp3.y=p2.y-p3.y;
    if ((tp1.x*tp2.y-tp1.y*tp2.x)*(tp2.x*tp3.y-tp2.y*tp3.x)>=0) return 1;
    else return 0;
}
int main()
{
    Point p1,p2,p3,p4;
	int r,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",
              &p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y,&p4.x,&p4.y);
		r=lineintersect(p1,p2,p3,p4);
		if(r==1)puts("YES");
		else puts("NO");
    }
    return 0;
}
