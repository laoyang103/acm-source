#include<stdio.h>
#include<string.h>
int array[100][100];//存贮输入数据
int memory[100][100];//动态规划记忆数组
int max(int a,int b)//求两数的最大值
{
	return a>b?a:b;
}
int DP(n,i,j)//动态规划
{
	if(i == n-1)//到达最底层
	{
		return array[i][j];
	}
	if(-1 == memory[i][j])//(i,j)未计算过，则计算它
	{
		memory[i][j]=max(DP(n,i+1,j),DP(n,i+1,j+1))+array[i][j];
	}
	return memory[i][j];
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
		memset(memory,-1,sizeof(memory));//将数组memory所有元素置成-1
		printf("%d\n",DP(n,0,0));
	}
	return 0;
}
/*
(i,j)方格每次只能走到(i+1,j)和(i+1,j+1)两个方格
设f(i,j)为计算(i,j)方格到达底层的最大数之和，
可得方程f(i,j)=array(i,j)+max(f(i+1,j),f(i+1,j+1));
递归终止条件：到达最底层.
*/
