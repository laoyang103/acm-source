//未通过WA
#include <stdio.h>
#include <string.h>
#define MAX_VALUE 1000000000
int graph[1001][1001];
void resetGraph(int n)
{
	int i,j,k;
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			graph[i][j]=MAX_VALUE;
		}
	}
}
void floyd(int n)
{
	int i,j,k,t;
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			for(k=0;k<n;++k)
			{
				t = graph[i][k]+graph[k][j];
				if(graph[i][j] > t)
				{
					graph[i][j]=t;
				}
			}
		}
	}
}
int main()
{
	int t,s,d;//t条路，s个相邻城市，d个想去的地方
	int a,b,time;
	int i;
	int min;
	int n;
	while(scanf("%d%d%d",&t,&s,&d)!=EOF)
	{
		//memset(graph,-1,sizeof(graph));
		resetGraph(1001);
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
		floyd(n+1);
		min=MAX_VALUE;
		for(i=0;i<d;++i)
		{
			scanf("%d",&a);
			if(graph[0][a]>0 && min>graph[0][a])
			{
				min=graph[0][a];
			}
		}
		if(min == MAX_VALUE)
		{
			min=0;
		}
		printf("%d\n",min);
		#if 0
		for(i=0;i<=n;++i)
		{
			printf("%d ",graph[0][i]);
		}
		printf("\n");
		#endif
	}
	return 0;
}
