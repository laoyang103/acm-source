#include <stdio.h>
int isInclude7(int d)
{
	int i;
	if(d%7 == 0)
	{
		return 1;
	}
	while(d!=0)
	{
		if(d%10 == 7)
		{
			return 1;
		}
		else d /= 10;
	}
	return 0;
}
int main()
{
	int n,i;
	while(scanf("%d",&n)==1)
	{
		for(i=7;i<=n;++i)
		if(isInclude7(i))	
		{
			printf("%d\n",i);
		}
	}
	return 0;
}
