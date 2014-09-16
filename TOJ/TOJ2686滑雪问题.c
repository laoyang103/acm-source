#include <stdio.h>
#include <string.h>
int array[101][101];
int memory[101][101];//记忆数组
int direction[4][2]={-1,0, 1,0, 0,-1, 0,1};//上下左右四方向
int row;//行
int col;//列
int DP(int r,int c)
{
	int i,y,x,temp;
	int max;
	if(memory[r][c]==0)//未计算过，则进行计算
	{
		max=0;
		for(i=0;i<4;++i)//搜索上下左右四个方向
		{
			y=r+direction[i][0];
			x=c+direction[i][1];
			if(y>=0 && y<row && x>=0 && x<col)
			{
				if(array[r][c] > array[y][x])
				{
					temp=DP(y,x)+1;
					if(max < temp)max=temp;
				}
			}
		}
		if(max == 0) max=1;//当前点是最低点，则会出现max=0.
		memory[r][c]=max;
	}
	return memory[r][c];
}
int main()
{
	int i,j;
	int temp,max;
	while(scanf("%d%d",&row,&col)==2)
	{
		for(i=0;i<row;++i)
		{
			for(j=0;j<col;++j)
			{
				scanf("%d",&array[i][j]);
			}
		}
		memset(memory,0,sizeof(memory));
		max=0;
		for(i=0;i<row;++i)
		{
			for(j=0;j<col;++j)
			{
				temp=DP(i,j);
				if(max < temp)
				{
					max=temp;
				}
			}
		}
		printf("%d\n",max);
	}
	return 0;
}
