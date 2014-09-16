#include <stdio.h>
int main()
{
	int x1,y1,x2,y2;
	int n,i;
	int t;
	while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2)!=EOF)
	{
		if(x2<x1){t=x2;x2=x1;x1=t;}
		printf("%d",x2-x1+3);
		printf(" %d %d",x1,y1);
		for(i=x1;i<=x2;++i)
		{
			printf(" %d %d",i,y2);
		}
		printf(" %d %d\n",x2,y1);
	}
	return 0;
}
