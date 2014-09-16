#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//kruskal算法
typedef struct
{
	int va;
	int vb;
	int cost;//边(va,vb)的权重
}Graph;

Graph graph[75];
int gIndex;	//记录边的个数
int parent[26];//记录每个结点的父节点或祖先结点

int cmp(const void *a,const void *b)//qsort函数的回调
{
	return ((Graph*)a)->cost - ((Graph*)b)->cost;
}

void resetParent(int n)//将每个结点的父节点置为它本身
{
	int i;
	for(i=0;i<n;++i)
	{
		parent[i]=i;
	}
}

int getRoot(int v)//获得结点所在树的树根
{
	while(v != parent[v])
	{
		v=parent[v];
	}
	return v;
}

int kruskal()//克鲁斯卡尔求最小生成树算法
{
	int i;
	int minCost=0;//最小花费
	int a,b;
	resetParent(26);
	qsort(graph,gIndex,sizeof(Graph),cmp);
	for(i=0; i<gIndex;++i)
	{
		a=graph[i].va;
		b=graph[i].vb;
		parent[a]=getRoot(a);
		parent[b]=getRoot(b);
		/*如果该边所依附的两个结点不在同一棵树中，
		则将该边加入最小生成树中。
		*/
		if(parent[a] != parent[b])
		{
			minCost += graph[i].cost;
			parent[parent[a]] = parent[b];
		}
	}
	return minCost;
}

int main()
{
	int n,k,cost;
	int i,j;
	char a[2],b[2];
	while(1)
	{
		scanf("%d",&n);
		if(0 == n)
		{
			break;
		}
		gIndex=0;
		for(i=0;i<n-1;++i)
		{
			scanf("%s%d",a,&k);
			for(j=0;j<k;++j)
			{
				scanf("%s%d",b,&cost);
				graph[gIndex].va=a[0]-'A';//将字符A映射到0，依次往后推
				graph[gIndex].vb=b[0]-'A';
				graph[gIndex].cost=cost;
				++gIndex;
			}
		}
		printf("%d\n",kruskal());
	}
	return 0;
}
