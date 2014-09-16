#include <iostream>
#include <cstring>
using namespace std;
#define MAX 310	//迷宫数组的最大界限，至少302
const int INFINITY = 10000;//定义一个最大数
//本身及四个方向
int direction[5][2]={{0,0},{-1,0},{1,0},{0,-1},{0,1} };
int maze[MAX][MAX];//迷宫，记录每个点的最小爆炸时间
int mark[MAX][MAX];//标记数组,标记是否访问过
int bfs()//广度优先搜索
{
	int q[3700];
	int front=0;
	int tail=0;
	int qsize=3700;
	mark[0][0]=1;
	q[front++]=0;
	q[front++]=0;
	q[front++]=0;
//	q.push(0);//压入行标
//	q.push(0);//压入列标
//	q.push(0);//压入时间
	int r,c;
	int t;
	while(front != tail)
	{
/*		r=q.front();//取出行标
		q.pop();
		c=q.front();//取出列标
		q.pop();
		t=q.front();//取出走到当前点所用时间
		q.pop();
*/		
		r=q[tail];
		tail=(tail+1)%qsize;
		c=q[tail];
		tail=(tail+1)%qsize;
		t=q[tail];
		tail=(tail+1)%qsize;
		if(INFINITY == maze[r][c])//到达安全地带
		{
			return t;
		}
		for(int d=1;d<5;++d)//搜索(r,c)的周围四个方向
		{
			int dy=direction[d][0]+r;
			int dx=direction[d][1]+c;
			if(dy>=0 && dy<MAX && dx>=0 && dx<MAX)
			{
				if(t<maze[dy][dx]-1 && mark[dy][dx]==0)
				{
					mark[dy][dx]=1;
				/*	q.push(dy);
					q.push(dx);
					q.push(t+1);
				*/
					q[front]=dy;
					front=(front+1)%qsize;
					q[front]=dx;
					front=(front+1)%qsize;
					q[front]=t+1;
					front=(front+1)%qsize;
				}
			}
		}
	}
	return -1;
}
int main()
{
	//初始化迷宫数组
	for(int i=0;i<MAX;++i)
	{
		for(int j=0;j<MAX;++j)
		{
			maze[i][j]=INFINITY;
		}
	}
	//初始化标记数组
	memset(mark,0,sizeof(mark));
	int n;
	cin>>n;
	int x,y,t;
	int dx,dy;
	for(int i=0;i<n;++i)
	{
		cin>>x>>y>>t;
		//设置当前点和周围4点的爆炸时间
		for(int d=0;d<5;++d)
		{
			dy=direction[d][0]+y;
			dx=direction[d][1]+x;
			if(dy>=0 && dy<MAX && dx>=0 && dx<MAX)
			{
				if(t<maze[dy][dx])
				{
					maze[dy][dx]=t;
				}
			}
		}
	}
	cout<<bfs()<<endl;
	return 0;
}
