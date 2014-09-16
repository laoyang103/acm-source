#include <stdio.h>
#include <string.h>
#define INFINITY 2000000000//定义无穷大
int path[100][100];//迷宫数据
int memory[100][100];//记忆数组
int row;//行数
int col;//列数
int min(int a,int b)
{
	return a<b?a:b;
}
int dfs(int si,int sj)//深度优先搜索
{
	if(si>=row || sj>=col)
	{
		return INFINITY;//超出边界
	}
	if(si==row-1 && sj==col-1)//到达终点
	{
		return path[si][sj];
	}
	if(memory[si][sj]==-1)//未访问过
	{
		memory[si][sj]=min(dfs(si+1,sj),dfs(si,sj+1))+path[si][sj];
	}
	return memory[si][sj];
}
int main()
{
	int i,j;
	while(scanf("%d%d",&row,&col)!=EOF)
	{
		for(i=0;i<row;++i)
		{
			for(j=0;j<col;++j)
			{
				scanf("%d",&path[i][j]);
			}
		}
		memset(memory,-1,sizeof(memory));
		printf("%d\n",dfs(0,0));
	}
	return 0;
}
/*
4 6
3 4 3 2 5 2
1 6 7 5 3 1
2 1 8 6 9 1
7 10 4 6 7 8

1 1
100

2 2
2 100
200 2

3 3
0 0 0
0 0 0
0 0 0
*/
