//已通过
#include <cstdio>
#include <map>
#include <set>
using namespace std;

/*
map的特点：不允许有重复的key，故可以用来记录边数，也可以判断
一个结点是否有两个父节点
*/
map<int,int> tree;//存贮边

//set的特点：不允许有重复的点存在，故可以使用它来记录有哪些结点。
set<int> node;//存贮点

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
				//node.size()!=0判断是否是空树
				//node.size()-1 != tree.size()结点数总比边数多1个
				if(node.size()!=0 && node.size()-1 != tree.size() )
				{
					bTree=false;
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
			node.clear();
			++testCase;
		}
		else
		{ 
			if(bTree)
			{
				if(tree[b] == 0)
				{
					tree[b]=a;//记录结点的父节点
					node.insert(a);//记录结点
					node.insert(b);
				}
				else//一个点有两个父节点，则不是树
				{
					bTree=false;
				}
			}
		}
	}
	return 0;
}
