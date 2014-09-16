#include <cstdio>
#include <queue>
using namespace std;
//������Χ8������
int direction[8][2]={{-1,-1},{-1,0},{-1,1},
					{0,-1},{0,1},
					{1,-1},{1,0},{1,1} };
int island[1000][1000];
int row,col;//�С���
//�����������
void bfs(int r,int c)
{
	queue<int> q;
	island[r][c]=-1;
	q.push(r);//ѹ���б�
	q.push(c);//ѹ���б�
	int qr,qc;
	int nr,nc;
	while(!q.empty())
	{
		qr=q.front();//ȡ���б�
		q.pop();
		qc=q.front();//ȡ���б�
		q.pop();
		//������Χ8����
		for(int i=0;i<8;++i)
		{
			nr=direction[i][0]+qr;
			nc=direction[i][1]+qc;
			if(nr>=0 && nr<row && nc>=0 && nc<col)
			{
				if(island[nr][nc]>0)//δ���ʹ�
				{
					island[nr][nc]=-1;//���Ϊ����
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
	int mark;//��¼�������
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
			//���ĳ�㼴û�б����ʹ���Ҳ���Ǻò�ƺ���������
			//�ø�������ѷ��ʹ�
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
//����������������������ݷ�Χ�ϴ���Ȼ����ջ���
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
