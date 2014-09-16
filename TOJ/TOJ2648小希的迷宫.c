#include <stdio.h>
#include <string.h>
int parent[100001];

int getParent(int v)
{
	while(v != parent[v])
	{
		v=parent[v];
	}
	return v;
}
void resetParent()
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
	int result=1;
	int i=0;
	int maxV=0;
	int t1,t2;
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
			if(1 == result)
			{
				for (i=1;i<=maxV;++i)
				{
					if (getParent(i) != getParent(maxV))
					{
						result=0;
						break;
					}
				}
			}
			if(1 == result)
			{
				puts("Yes");
			}
			else
			{
				puts("No");
			}
			result=1;
			resetParent();
		}
		else if(1 == result)
		{
			if(maxV < a)maxV=a;
			if(maxV < b)maxV=b;

			parent[a]=getParent(a);
			parent[b]=getParent(b);
			if(parent[a]==parent[b])
			{
				result=0;
			}
			else
			{
				parent[parent[b]]=parent[a];
			}
		}
	}
	return 0;
}
