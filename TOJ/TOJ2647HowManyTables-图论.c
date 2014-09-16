#include <stdio.h>
#include <string.h>
int graph[1002][1002];//�ڽӾ���
int mark[1002];
int g_verteices;//������
void DFS(int vertex)//�����������
{
	int v;
	for(v=1;v<=g_verteices;++v)
	{
		if((v != vertex) && (0 == mark[v])&& (1 == graph[vertex][v]))
		{
			mark[v]=1;
			DFS(v);
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
	int t;//��������
	int n;//n���
	int v1,v2;
	scanf("%d",&t);
	while(t--)
	{
		memset(graph,0,sizeof(graph));
		scanf("%d%d",&g_verteices,&n);
		while(n--)//����n���
		{
			scanf("%d%d",&v1,&v2);
			graph[v1][v2]=1;
			graph[v2][v1]=1;//����ͼ��v1->v2 ��v2->v1
		}
		printf("%d\n",DFSGraph());
	}
	return 0;
}
