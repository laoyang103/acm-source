#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//kruskal�㷨
typedef struct
{
	int va;
	int vb;
	int cost;//��(va,vb)��Ȩ��
}Graph;

Graph graph[75];
int gIndex;	//��¼�ߵĸ���
int parent[26];//��¼ÿ�����ĸ��ڵ�����Ƚ��

int cmp(const void *a,const void *b)//qsort�����Ļص�
{
	return ((Graph*)a)->cost - ((Graph*)b)->cost;
}

void resetParent(int n)//��ÿ�����ĸ��ڵ���Ϊ������
{
	int i;
	for(i=0;i<n;++i)
	{
		parent[i]=i;
	}
}

int getRoot(int v)//��ý��������������
{
	while(v != parent[v])
	{
		v=parent[v];
	}
	return v;
}

int kruskal()//��³˹��������С�������㷨
{
	int i;
	int minCost=0;//��С����
	int a,b;
	resetParent(26);
	qsort(graph,gIndex,sizeof(Graph),cmp);
	for(i=0; i<gIndex;++i)
	{
		a=graph[i].va;
		b=graph[i].vb;
		parent[a]=getRoot(a);
		parent[b]=getRoot(b);
		/*����ñ���������������㲻��ͬһ�����У�
		�򽫸ñ߼�����С�������С�
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
				graph[gIndex].va=a[0]-'A';//���ַ�Aӳ�䵽0������������
				graph[gIndex].vb=b[0]-'A';
				graph[gIndex].cost=cost;
				++gIndex;
			}
		}
		printf("%d\n",kruskal());
	}
	return 0;
}
