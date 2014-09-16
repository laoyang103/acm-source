#include<stdio.h>
#include<math.h>
/*向量解法：未通过*/
int main()
{
	int x1,y1;
	int x2,y2;
	int v1,v2,r;
	double s;
	double tha;
	double t;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	scanf("%d%d%d",&v1,&v2,&r);
	tha=(double)(x1*x2+y1*y2)/(double)(r*r);
	tha=acos(tha);
	s=tha*r;
	t=s/(double)(v1+v2);
	t=t/60.0;
	printf("%.1lf\n",t);
	return 0;
}
