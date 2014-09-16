#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define PI 3.1415926

typedef struct
{
	char name[20];
	double area;
}Shape;
Shape sh[100];
int shIndex=0;

//比较函数
int cmp(const void *a,const void *b)
{
	Shape *pa=(Shape*)a;
	Shape *pb=(Shape*)b;
	double r=pb->area - pa->area;//降序
	int t;
	if(r > 1e-6)t=1;//r>0
	else if(r < -(1e-6))t=-1;//<0
	else//r=0;
	{
		t=strcmp(pa->name,pb->name);
	}
	return t;
}
//获得线段长度
double getDis(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void circle()
{
	static int cid=0;//标记数据组数
	double x,y,r;
	++cid;
	scanf("%lf%lf%lf",&x,&y,&r);
	sprintf(sh[shIndex].name,"circle%d",cid);
	sh[shIndex].area=PI*r*r;
	++shIndex;
}
void rectangle()
{
	static int rid=0;
	double x1,y1,x2,y2;
	++rid;
	scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
	sprintf(sh[shIndex].name,"rectangle%d",rid);
	sh[shIndex].area=fabs((x1-x2)*(y1-y2));
	++shIndex;
}
void triangle()
{
	static int tid=0;
	double x1,y1,x2,y2,x3,y3;
	double a,b,c;
	++tid;
	scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
	//求得三角形3边长
	a=getDis(x1,y1,x2,y2);
	b=getDis(x1,y1,x3,y3);
	c=getDis(x2,y2,x3,y3);
	sprintf(sh[shIndex].name,"triangle%d",tid);
	sh[shIndex].area=(1.0/4)*sqrt((a+b+c)*(a+b-c)*(b+c-a)*(a+c-b)) ;
	++shIndex;
}
int main()
{
	char shape[20];
	int i;
	while(scanf("%s",shape)!=EOF)
	{
		if(strcmp(shape,"rectangle")==0)
		{
			rectangle();
		}
		else if(strcmp(shape,"triangle")==0)
		{
			triangle();
		}
		else
		{
			circle();
		}
	}
	qsort(&sh,shIndex,sizeof(Shape),cmp);//排序
	for(i=0;i<shIndex;++i)
	{
		printf("%s %.3lf\n",sh[i].name,sh[i].area);
	}
	return 0;
}
