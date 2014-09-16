//δͨ��WA
#include <stdio.h>
#include <string.h>
#define MAX_VALUE 0x1000000000
int graph[1001][1001];
int g_MinCost[1001];
void dijkstra(int n)
{
	int i,j,t;
	int min,mIndex;
	int minCost[1001];
	//��ʼ��minCost��,Ϊ0�㵽���е�ľ���
	for(i=0;i<n;++i)
	{
		if(graph[0][i] == 0)
		{
			minCost[i]=0;
			g_MinCost[i]=0;
		}
		else
		{
			minCost[i]=MAX_VALUE;
			g_MinCost[i]=MAX_VALUE;
		}
	}
	for(j=0;j<n;++j)
	{
		min=MAX_VALUE;
		mIndex=-1;
		for(i=0;i<n;++i)//��minCost�����ҵ���С���ѵ�һ����
		{
			if(min > minCost[i])
			{
				min=minCost[i];
				mIndex=i;
			}
		}
		if(mIndex == -1)
		{
			break;
		}
		for(i=0;i<n;i++)
		{
			if(graph[mIndex][i]>0)//�ɵ���
			{
				t=minCost[mIndex]+graph[mIndex][i];
				if(t < g_MinCost[i])
				{
					g_MinCost[i]=minCost[i]=t;
				}
			}
		}
		minCost[mIndex]=MAX_VALUE;
	}
}
int main()
{
	int t,s,d;//t��·��s�����ڳ��У�d����ȥ�ĵط�
	int a,b,time;
	int i;
	int min;
	int n;
	while(scanf("%d%d%d",&t,&s,&d)!=EOF)
	{
		memset(graph,-1,sizeof(graph));
		n=-1;
		for(i=0;i<t;++i)
		{
			scanf("%d%d%d",&a,&b,&time);
			graph[a][b]=graph[b][a]=time;
			if(n<a)n=a;
			if(n<b)n=b;
		}
		for(i=0;i<s;++i)
		{
			scanf("%d",&a);
			graph[0][a]=graph[a][0]=0;
		}
		dijkstra(n+1);
		min=MAX_VALUE;
		for(i=0;i<d;++i)
		{
			scanf("%d",&a);
			if(min>g_MinCost[a])
			{
				min=g_MinCost[a];
			}
		}
		if(min == MAX_VALUE)
		{
			min=0;
		}
		printf("%d\n",min);
	}
	return 0;
}
