//非递归版本
#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

int graph[1001][1001];//邻接矩阵
int mark[1001];
int g_verteices;//顶点数

void DFS(int vertex)//深度优先搜索
{
	stack<int> g_stack;
	g_stack.push(vertex);
	while(!g_stack.empty())
	{
		vertex=g_stack.top();
		g_stack.pop();
		for(int v=1;v<=g_verteices;++v)
		{
			if((v != vertex) && (0 == mark[v])&& (1 == graph[vertex][v]))
			{
				mark[v]=1;
				g_stack.push(v);
			}
		}
	}
}
int DFSGraph()
{
	int i;
	int tables=0;
	memset(mark,0,sizeof(mark));
	for(i=1;i<=g_verteices;++i)
	{
		if(0 == mark[i])
		{
			++tables;
			mark[i]=0;
			DFS(i);
		}
	}
	return tables;
}
int main()
{
	int t;//测试组数
	int n;//n组边
	int v1,v2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&g_verteices,&n);
		memset(graph,0,sizeof(graph));
		while(n--)//输入n组边
		{
			scanf("%d%d",&v1,&v2);
			graph[v1][v2]=1;
			graph[v2][v1]=1;//无向图，v1->v2 则v2->v1
		}
		printf("%d\n",DFSGraph());
	}
	return 0;
}
