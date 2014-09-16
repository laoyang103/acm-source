#include <cstdio>
#include <cstring>
#include <list>
using namespace std;

int parent[100001];//存贮结点的父节点

int getRoot(int v)//获得结点的根结点
{
	while(v != parent[v])
	{
		v=parent[v];
	}
	return v;
}
void resetParent()//重置parent数组
{
	int i;
	for(i=0;i<100001;++i)
	{
		parent[i]=i;
	}
}
int main()
{
	int a,b;
	bool result=true;
	list<int> lst;//记录数据中有哪些结点
	resetParent();
	while(1)
	{
		scanf("%d%d",&a,&b);
		if(-1 == a && -1 == b)
		{
			break;
		}
		else if(0==a && 0==b)
		{
			if(result)//判断是否连通
			{
				list<int>::const_iterator it,itEnd;
				it=lst.begin();
				itEnd=lst.end();
				int t=getRoot(*it);
				for (++it; it!=itEnd; ++it)
				{
					if (getRoot(*it) != t)//树中有两个根结点，说明不连通
					{
						result=false;
						break;
					}
				}
			}
			if(result)
			{
				puts("Yes");
			}
			else
			{
				puts("No");
			}
			//重置数据
			result=true;
			resetParent();
			lst.clear();
		}
		else if(1 == result)
		{
			lst.push_back(a);
			lst.push_back(b);

			parent[a]=getRoot(a);
			parent[b]=getRoot(b);
			if(parent[a]==parent[b])
			{
				result=false;
			}
			else
			{
				parent[parent[b]]=parent[a];
			}
		}
	}
	return 0;
}
