//Î´Í¨¹ý TLE
#include <cstdio>
#include <map>
using namespace std;
map<int,int> tree;

int getRoot(int v)
{
	int parent=tree[v];
	while(0!=parent && v!=parent)
	{
		v=parent;
		parent=tree[v];
	}
	return v;
}

int main()
{
	int n,i;
	int a,b;
	int ra,rb;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;++i)
		{
			scanf("%d%d",&a,&b);
			ra=getRoot(a);
			rb=getRoot(b);
			tree[a]=rb;
			tree[b]=rb;
			tree[ra]=rb;
		}
		map<int,int> mCount;
		map<int,int>::iterator it,itEnd;
		it=tree.begin();
		itEnd=tree.end();
		for(;it!=itEnd;++it)
		{
			ra=getRoot(it->first);
			rb=getRoot(it->second);
			if(ra != it->first)
			{
				mCount[ra]=mCount[ra]+1;
			}
			if(rb != it->second)
			{
				mCount[rb]=mCount[rb]+1;
			}
		}
		it=mCount.begin();
		itEnd=mCount.end();
		int max=0;
		for(;it!=itEnd;++it)
		{
			if(max < it->second)
			{
				max=it->second;
			}
		}
		printf("%d\n",max+1);
		tree.clear();
		mCount.clear();
	}
	return 0;
}
