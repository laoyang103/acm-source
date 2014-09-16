#include <stdio.h>
#include <math.h>
int isSqrtNumber(int d)
{
	if(d<0)d=-d;
	int sq=sqrt(d);
	if(sq*sq == d)
	{
		return 1;
	}
	else return 0;
}
int isZRS(int a,int b)
{
	if(isSqrtNumber(a+b)==1 && isSqrtNumber(a-b)==1)
	{
		return 1;
	}
	else return 0;
}
int main()
{
	int a,b;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		if(isZRS(a,b)==1)
		{
			puts("YES");
		}
		else puts("NO");
	}
	return 0;
}
