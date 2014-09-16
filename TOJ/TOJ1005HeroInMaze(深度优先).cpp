#include <cstdio>
#include <cstring>
using namespace std;
//�������������ĸ�����
const int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
char maze[21][21];	//�Թ�
int mark[21][21];	//�������
int row;//�Թ�����
int col;//�Թ�����
int destr;
int destc;
/*�����������
**���(sc,sr)
**�յ�(dc,dr)
**����ʱ��maT
*/
int bfs(int sr,int sc,int t)
{
	mark[sr][sc]=t;
	if(r==destr && c==destc)
	{
		if(t<=maxT)return t;
		else return -1;//��������ʱ��
	}
	else if(t>maxT)
	{
		return -1;//�Ѿ�����ʱ������
	}
	//����Χ4�����������
	for(int d=0;d<4;++d)
	{
		int dr=r+dir[d][0];
		int dc=c+dir[d][1];
		if(dr>=0 && dr<row && dc>=0 && dc<col)
		{
			//���δ���ʹ������ҿ���ͨ�����򽫸õ�������
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
	int sr,sc;//���
	int dr,dc;//�յ�
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
				{//��¼���
					sr=i;
					sc=j;
				}
				else if(maze[i][j]=='P')
				{//��¼Ŀ��㣨�յ㣩
					dr=i;
					dc=j;
				}
			}
		}
		memset(mark,0,sizeof(mark));
		int r=bfs(sr,sc,dr,dc,day);//��������
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
