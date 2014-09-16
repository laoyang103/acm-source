#include<stdio.h>
#include<math.h>
#include<list>
typedef struct ASatrPath
{
	int i,j;	//当前点的行号和列号
	int g,f;	//估价函数f=g+h，g为当前点到起点的估价，h为当前点到终点的估价
	char weigth;//当前点的权值
	int isIn;	//0未处理，1在open表中，2已处理过
	ASatrPath* parent;//父节点
}AStarPath;
AStarPath maze[20][20];//迷宫
const int dir[4][2]={-1,0,0,-1,0,1,1,0};//定义上下左右4个方向
int desti,destj;	//目标点的下标
int length,height;	//迷宫的长和高，即行数和列数
std::list<AStarPath*> open;//open表，记录将要访问的点。
//A*寻路算法
AStarPath* AStar(int srci,int srcj)
{
	open.clear();//将open表清空
	//将第一个点加入open表中准备访问
	AStarPath* parent=&maze[srci][srcj];
	parent->isIn=1;
	open.push_back(parent);
	//开始搜索
	while(!open.empty())
	{
		//找到估价值最小的结点
		std::list<AStarPath*>::iterator it=open.begin();
		std::list<AStarPath*>::iterator it_start,it_end=open.end();
		for(it_start=it;it_start!=it_end;++it_start)
		{
			if((*it)->f > (*it_start)->f)
				it=it_start;
		}
		parent=*it;
		if(parent->i==desti && parent->j==destj)
		{
			return parent;
		}
		open.erase(it);//将估价最小的点从open表中删除
		parent->isIn=2;//将它标记为已访问
		//对他周围4个点进行搜索
		for(int d=0;d<4;++d)
		{
			int i=dir[d][0]+parent->i;
			int j=dir[d][1]+parent->j;
			if(i>=0 && i<height && j>=0 && j<length)
			{
				AStarPath* v=&maze[i][j];
				if(v->weigth=='*')
					continue;
				//计算到目标点的估价值
				int h=abs(i-desti)+abs(j-destj);
				if(v->isIn==1)//在open表中
				{
					if(v->f > parent->g+1+h)
					{//如果新的路径的估价要小于原来的估价，则修改。
						v->g=parent->g+1;
						v->f=v->g+h;
						v->parent=parent;
					}
				}
				else if(v->isIn==0)
				{//如果还未访问，就加入open表准备访问
					v->parent=parent;
					v->g=parent->g+1;
					v->isIn=1;
					v->f=v->g+h;
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
	int srci,srcj;	//起点下标
	int day;		//天数
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
				while((t=getchar())=='\n');//去掉换行符
				maze[i][j].weigth=t;
				if(maze[i][j].weigth=='S')
				{//得到起点的下标
					srci=i;
					srcj=j;
				}
				if(maze[i][j].weigth=='P')
				{//得到终点的下标
					desti=i;
					destj=j;
				}
				maze[i][j].i=i;
				maze[i][j].j=j;
				maze[i][j].g=0;
				maze[i][j].f=0;
				maze[i][j].isIn=0;
				maze[i][j].parent=NULL;
			}
		}
		AStarPath* p=AStar(srci,srcj);
		if(p)
		{
			int i=-1;
			while(p)
			{//判断路径长度是否超过天数
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