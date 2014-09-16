#include<stdio.h>
int func(int n,int m)
{
	int count=0;
	int i,j;
	for(i=m-1;i>=0;--i)
	{
		for(j=n;j>i;--j)
			count+=j;
	}
	return count;
}
int main()
{
	int n,m;
	int testCase;
	scanf("%d",&testCase);
	while(testCase--)
	{
		scanf("%d%d",&n,&m);
		printf("%d\n",func(n,m));
	}
	return 0;
}
