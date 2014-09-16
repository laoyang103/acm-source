#include<stdio.h>
#include<list>
typedef struct ASatrPath
{
	int i,j;	//��ǰ����кź��к�
	char weigth;//��ǰ���Ȩֵ
	int isIn;	//0δ����1��open���У�2�Ѵ����
	ASatrPath* parent;//���ڵ�
}AStarPath;
AStarPath maze[20][20];//�Թ�
const int dir[4][2]={-1,0,0,-1,0,1,1,0};//������������4������
int desti,destj;	//Ŀ�����±�
int length,height;	//�Թ��ĳ��͸ߣ�������������
std::list<AStarPath*> open;//open����¼��Ҫ���ʵĵ㡣
//A*Ѱ·�㷨
AStarPath* AStar(int srci,int srcj)
{
	open.clear();//��open�����
	//����һ�������open����׼������
	AStarPath* parent=&maze[srci][srcj];
	parent->isIn=1;
	open.push_back(parent);
	//��ʼ����
	while(!open.empty())
	{
		//�ҵ�����ֵ��С�Ľ��
		parent=open.front();
		open.pop_front();//��������С�ĵ��open����ɾ��
		if(parent->i==desti && parent->j==destj)
		{
			return parent;
		}
		parent->isIn=2;//�������Ϊ�ѷ���
		//������Χ4�����������
		for(int d=0;d<4;++d)
		{
			int i=dir[d][0]+parent->i;
			int j=dir[d][1]+parent->j;
			if(i>=0 && i<height && j>=0 && j<length)
			{
				AStarPath* v=&maze[i][j];
				if(v->weigth=='*')
					continue;
				if(v->isIn==0)
				{//�����δ���ʣ��ͼ���open��׼������
					v->parent=parent;
					v->isIn=1;
					open.push_back(v);
				}
			}
		}
	}
	return NULL;
}
int main()
{
	int i,j;
	int srci,srcj;	//����±�
	int day;		//����
	while(1)
	{
		scanf("%d%d%d",&length,&height,&day);
		if(length+height+day==0)
			break;
		srci=srcj=0;
		for(i=0;i<height;++i)
		{
			for(j=0;j<length;++j)
			{
				char t;
				while((t=getchar())=='\n');//ȥ�����з�
				maze[i][j].weigth=t;
				if(maze[i][j].weigth=='S')
				{//�õ������±�
					srci=i;
					srcj=j;
				}
				if(maze[i][j].weigth=='P')
				{//�õ��յ���±�
					desti=i;
					destj=j;
				}
				maze[i][j].i=i;
				maze[i][j].j=j;
				maze[i][j].isIn=0;
				maze[i][j].parent=NULL;
			}
		}
		AStarPath* p=AStar(srci,srcj);
		if(p)
		{
			int i=-1;
			while(p)
			{//�ж�·�������Ƿ񳬹�����
				p=p->parent;
				++i;
			}
			if(i<=day)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else
			printf("NO\n");
	}
	return 0;
}