#include <cstdio>
#include <queue>
using namespace std;
//定义周围8个方向
int direction[8][2]={{-1,-1},{-1,0},{-1,1},
					{0,-1},{0,1},
					{1,-1},{1,0},{1,1} };
int island[1000][1000];
int row,col;//行、列
//广度优先搜索
void bfs(int r,int c)
{
	queue<int> q;
	island[r][c]=-1;
	q.push(r);//压入行标
	q.push(c);//压入列标
	int qr,qc;
	int nr,nc;
	while(!q.empty())
	{
		qr=q.front();//取出行标
		q.pop();
		qc=q.front();//取出列标
		q.pop();
		//搜索周围8个点
		for(int i=0;i<8;++i)
		{
			nr=direction[i][0]+qr;
			nc=direction[i][1]+qc;
			if(nr>=0 && nr<row && nc>=0 && nc<col)
			{
				if(island[nr][nc]>0)//未访问过
				{
					island[nr][nc]=-1;//标记为负数
					q.push(nr);
					q.push(nc);
				}
			}
		}
	}
}
int main()
{
	int amount=0;
	int i,j;
	int mark;//记录岛屿个数
	scanf("%d%d",&row,&col);
	for(i=0;i<row;++i)
	{
		for(j=0;j<col;++j)
		{
			scanf("%d",&island[i][j]);
		}
	}
	mark=0;
	for(i=0;i<row;++i)
	{
		for(j=0;j<col;++j)
		{
			//如果某点即没有被访问过，也不是好草坪，则访问它
			//用负数标记已访问过
			if(island[i][j]>0)
			{
				++mark;
				bfs(i,j);
			}
		}
	}
	printf("%d\n",mark);
	return 0;
}
/*
//深度优先搜索。但此题数据范围较大，深度会造成栈溢出
int dfs(int r,int c)
{
	int i;
	int nr,nc;
	island[r][c]=-1;
	for(i=0;i<8;++i)
	{
		nr=direction[i][0]+r;
		nc=direction[i][1]+c;
		if(nr>=0 && nr<row && nc>=0 && nc<col)
		{
			if(island[nr][nc]>0)
			{
				dfs(nr,nc);
			}
		}
	}
	return 0;
}*/
