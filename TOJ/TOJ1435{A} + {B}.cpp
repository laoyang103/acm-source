#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
void show(int data)
{
	printf(" %d",data);
}
int main()
{
	set<int> tree;
	int na,nb;
	int i;
	int data;
	while(scanf("%d%d",&na,&nb)==2)
	{
		for(i=0;i<na+nb;++i)
		{
			scanf("%d",&data);
			tree.insert(data);
		}
		set<int>::iterator it=tree.begin();
		printf("%d",*(it));
		for_each(++it,tree.end(),show);
		printf("\n");
		tree.clear();
	}
	return 0;
}
