//未通过 TLE
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
using namespace std;

#define MAX_SIZE 10000001
int parent[MAX_SIZE];
int counter[MAX_SIZE];

int getRoot(int v)
{
	int t;
	while(v!=parent[v])
	{
		t=v;
		v=parent[v];
		parent[t]=v;
	}
	return v;
}
int main()
{
	int n,i;
	int a,b;
	int ra,rb;
	int max=0;
	set<int> node;
	while(scanf("%d",&n)!=EOF)
	{
		max=0;
	//	memset(parent,0,sizeof(parent));
	//	memset(counter,0,sizeof(counter));
		for(i=0;i<n;++i)
		{
			scanf("%d%d",&a,&b);
			if((node.insert(a)).second)//如果不存在则插入
			{
				counter[a]=0;
				parent[a]=a;
			}
			if((node.insert(b)).second)
			{
				counter[b]=0;
				parent[b]=b;
			}
			ra=getRoot(a);
			rb=getRoot(b);
			parent[a]=rb;
			parent[b]=rb;
			parent[ra]=rb;
		}
		if(n>0)
		{
			set<int>::const_iterator sit,sitEnd;
			sit=node.begin();
			sitEnd=node.end();
			for(;sit!=sitEnd;++sit)
			{
				i = *sit;
				ra=getRoot(i);
				if(i != ra)//i不是根结点
				{
					parent[i]=ra;
					++counter[ra];
					if(max<counter[ra])
					{
						max=counter[ra];
					}
				}
			}
			++max;
			node.clear();
		}
		printf("%d\n",max);
	}
	return 0;
}
