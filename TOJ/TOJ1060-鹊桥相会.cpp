#include <cstdio>
using namespace std;
#define INFINITY 2000000000//定义个无穷大的数
char rStr[]="Can't Solve";
int main()
{
	int w,n;
	int pos,v;
	int t,mint=0;
	while(scanf("%d%d",&w,&n),(w!=0 && n!=0))
	{
		w*=1000;
		mint=INFINITY;
		for(int i=0;i<n;++i)
		{
			scanf("%d%d",&pos,&v);
			if(pos<=0 && v>0)
			{
				t=(w-pos)/v;//计算到达目的地的时间
				if(mint>t)mint=t;
			}
		}
		if(mint == INFINITY)puts(rStr);
		else printf("%d\n",mint);
	}
	return 0;
}
/*
只需要考虑到达目的地所用时间最短，且牛郎能够搭乘的鸟（即，坐标<=0）。
*/
