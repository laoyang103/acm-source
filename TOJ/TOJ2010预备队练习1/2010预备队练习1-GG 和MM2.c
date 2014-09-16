#include<stdio.h>
#include<math.h>
int main()
{
	int x1,y1;
	int x2,y2;
	int v1,v2,r;
	double s;//两者的圆弧距离
	double tha;//角度
	double t;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	scanf("%d%d%d",&v1,&v2,&r);
	tha=1.0-(double)((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))/(double)(2*r*r);
	tha=acos(tha);
	s=tha*r;
	t=s/(double)(v1+v2);
	t=t/60.0;
	printf("%.1lf\n",t);
	return 0;
}
