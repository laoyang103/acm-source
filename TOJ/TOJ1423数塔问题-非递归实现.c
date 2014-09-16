#include<stdio.h>
int array[100][100];//存贮输入数据
int max(int a,int b)//求两数的最大值
{
	return a>b?a:b;
}
int DP(n)//动态规划
{
	int i,j;
	for(i=n-2;i>=0;--i)
	{
		for(j=0;j<=i;++j)
		{
			array[i][j]=array[i][j]+max(array[i+1][j],array[i+1][j+1]);
		}
	}
	return array[0][0];
}
int main()
{
	int testTimes;//测试数据组数
	int n,i,j;
	scanf("%d",&testTimes);
	while(testTimes--)
	{
		scanf("%d",&n);//塔高
		for(i=0;i<n;++i)
		{
			for(j=0;j<=i;++j)
			{
				scanf("%d",&array[i][j]);
			}
		}
		printf("%d\n",DP(n));
	}
	return 0;
}

