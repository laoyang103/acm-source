#include <stdio.h>
#include <math.h>
int main()
{
	double x1,y1,r1;
	double x2,y2,r2;
	double distance;
	double temp;
	while(scanf("%lf%lf%lf",&x1,&y1,&r1) != EOF)
	{
		scanf("%lf%lf%lf",&x2,&y2,&r2);
		distance=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		if(distance > r1+r2)//相离
		{
			puts("2");
		}
		else if(distance == r1+r2)//相切
		{
			puts("1");
		}
		else
		{
			if(r1 < r2)
			{
				temp=r1;
				r1=r2;
				r2=temp;
			}
			if(distance+r2 < r1)//内含
			{
				puts("3");
			}
			else if(distance+r2 == r1)//内切
			{
				puts("1");
			}
			else//相交
			{
				puts("4");
			}
		}
	}
	return 0;
}
