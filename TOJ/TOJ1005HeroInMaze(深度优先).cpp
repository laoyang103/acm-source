#include <cstdio>
#include <cstring>
using namespace std;
//定义上下左右四个方向
const int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
char maze[21][21];	//迷宫
int mark[21][21];	//标记数组
int row;//迷宫行数
int col;//迷宫列数
int destr;
int destc;
/*广度优先搜索
**起点(sc,sr)
**终点(dc,dr)
**上限时间maT
*/
int bfs(int sr,int sc,int t)
{
	mark[sr][sc]=t;
	if(r==destr && c==destc)
	{
		if(t<=maxT)return t;
		else return -1;//超过上限时间
	}
	else if(t>maxT)
	{
		return -1;//已经超过时间上限
	}
	//对周围4个点进行搜索
	for(int d=0;d<4;++d)
	{
		int dr=r+dir[d][0];
		int dc=c+dir[d][1];
		if(dr>=0 && dr<row && dc>=0 && dc<col)
		{
			//如果未访问过，并且可以通过，则将该点加入队列
			if(mark[r][c]+1<mark[dr][dc] && maze[dr][dc]!='*')
			{
				dfs(dr,dc,mark[r][c]+1);     
			}
		}
	}
	return -1;
}
int main()
{
	int day;
	int sr,sc;//起点
	int dr,dc;//终点
	while(1)
	{
		scanf("%d%d%d",&col,&row,&day);
		if(row+col+day==0)break;
		getchar();
		for(int i=0;i<row;++i)
		{
			gets(maze[i]);
			for(int j=0;j<col;++j)
			{
				if(maze[i][j]=='S')
				{//记录起点
					sr=i;
					sc=j;
				}
				else if(maze[i][j]=='P')
				{//记录目标点（终点）
					dr=i;
					dc=j;
				}
			}
		}
		memset(mark,0,sizeof(mark));
		int r=bfs(sr,sc,dr,dc,day);//进行搜索
		if(r<0) puts("NO");			
		else
		{
			puts("YES");
		}
	}
	return 0;
}
/*
2 2 2
S.
.P
2 2 1
S.
.P
2 3 3
S.
**
.P
2 3 3
S.
..
.P
2 3 2
S.
..
.P
*/
/*
2 2 2
S.
.P
YES
2 2 1
S.
.P
NO
2 3 3
S.
**
.P
NO
2 3 3
S.
..
.P
YES
2 3 2
S.
..
.P
NO

*/
