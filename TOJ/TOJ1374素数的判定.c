#include <stdio.h>
#include <string.h>
#include <math.h>
char prim[3000];
void CalculatePrim()//筛选法判定素数
{
	int i,j;
	int n=3000;
	int m=sqrt(n);
	memset(prim,-1,sizeof(prim));
	for(i=2;i<=m;++i)
	{
		if(prim[i] == 0)continue;
		for(j=i+i;j<n;j+=i)
		{
			prim[j]=0;
		}
	}
}
int IsOk(int x,int y)
{
	int i;
	int r;
	for(i=x;i<=y;++i)
	{
		r=i*i+i+41;
		if(prim[r] == 0)return 0;
	}
	return 1;
}
int main()
{
	int x,y;
	CalculatePrim();
	while(1)
	{
		scanf("%d%d",&x,&y);
		if((0 == x) && (0 == y))break;
		if(x>y)
		{
			x=x+y;
			y=x-y;
			x=x-y;
		}
		if(IsOk(x,y))puts("OK");
		else puts("Sorry");
	}
	return 0;
}
