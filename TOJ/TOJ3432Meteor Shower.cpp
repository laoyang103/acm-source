#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 310	//�Թ�����������ޣ�����302
const int INFINITY = 10000;//����һ�������
//�����ĸ�����
int direction[5][2]={{0,0},{-1,0},{1,0},{0,-1},{0,1} };
int maze[MAX][MAX];//�Թ�����¼ÿ�������С��ըʱ��
int mark[MAX][MAX];//�������,����Ƿ���ʹ�
int bfs()//�����������
{
	queue<int> q;
	mark[0][0]=1;
	q.push(0);//ѹ���б�
	q.push(0);//ѹ���б�
	q.push(0);//ѹ��ʱ��
	int r,c;
	int t;
	while(!q.empty())
	{
		r=q.front();//ȡ���б�
		q.pop();
		c=q.front();//ȡ���б�
		q.pop();
		t=q.front();//ȡ���ߵ���ǰ������ʱ��
		q.pop();
		if(INFINITY == maze[r][c])//���ﰲȫ�ش�
		{
			return t;
		}
		for(int d=1;d<5;++d)//����(r,c)����Χ�ĸ�����
		{
			int dy=direction[d][0]+r;
			int dx=direction[d][1]+c;
			if(dy>=0 && dy<MAX && dx>=0 && dx<MAX)
			{
				if(t<maze[dy][dx]-1 && mark[dy][dx]==0)
				{
					mark[dy][dx]=1;
					q.push(dy);
					q.push(dx);
					q.push(t+1);
				}
			}
		}
	}
	return -1;
}
int main()
{
	//��ʼ���Թ�����
	for(int i=0;i<MAX;++i)
	{
		for(int j=0;j<MAX;++j)
		{
			maze[i][j]=INFINITY;
		}
	}
	//��ʼ���������
	memset(mark,0,sizeof(mark));
	int n;
	cin>>n;
	int x,y,t;
	int dx,dy;
	for(int i=0;i<n;++i)
	{
		cin>>x>>y>>t;
		//���õ�ǰ�����Χ4��ı�ըʱ��
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
