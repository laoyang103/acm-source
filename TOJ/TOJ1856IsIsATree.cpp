//未通过-TLE
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
	int a,b;
	int root,r;
	int testCase=1;
	bool bTree=true;
	while(1)
	{
		scanf("%d%d",&a,&b);
		if(a < 0 && b < 0 )
		{
			break;
		}
		else if(0 == a && 0 == b)
		{
			if(bTree)//判断是否是森林
			{
				map<int,int>::iterator it,itEnd;
				it=tree.begin();
				itEnd=tree.end();
				if(it == itEnd)
				{
					bTree=false;
				}
				else
				{
					root=getRoot(it->first);
					for(++it; it != itEnd; ++it)
					{
						r=getRoot(it->first);
						if(r != root)//不是同一棵树
						{
							bTree=false;
							break;
						}
						else
						{
							it->second=root;
						}
					}
				}
			}
			if(bTree)
			{
				printf("Case %d is a tree.\n",testCase);
			}
			else
			{
				printf("Case %d is not a tree.\n",testCase);
			}
			bTree=true;
			tree.clear();
			++testCase;
		}
		else
		{ 
			if(bTree)
			{
				if(tree[b] == 0)
				{
					tree[b]=a;
				}
				else
				{
					bTree=false;
				}
			}
		}
	}
	return 0;
}
