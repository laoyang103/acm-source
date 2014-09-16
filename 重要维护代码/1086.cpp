#include <stdio.h>
#include <stdlib.h>
int data[65] = {0};
bool findout = false;
int cmp(const void *pa,const void *pb)
{
	return *(int *)pb - *(int *)pa;
}
bool dfs(bool flag[],int depth,int n,int sum,int sticks)
{
	if(sticks == depth)
	{
		printf("%d\n",n);
		findout = true;
		return true;
	}
	int i,j,k = 0;
	int mem = 0;
	for(i = 0;i<sticks;i++)
	{
		if(!flag[i])
		{
			if(data[i]+sum <= n && mem != data[i])
			{
				mem = data[i];
				flag[i] = true;
				if(dfs(flag,depth+1,n,(sum+data[i])%n,sticks))
					return true;
				flag[i] = false;
				if(data[i] == n-sum || 0 == sum)
					return false;
			}
		}
	}
	return false;
}
/*
4
4 3 2 1
9
5 2 1 5 2 1 5 2 1
9
15 11 8 8 8 4 3 2 1
12
1 1 2 2 2 3 3 3 3 3 3 4
27
15 3 2 4 11 1 8 8 8 15 3 2 4 11 1 8 8 8 15 3 2 4 11 1 8 8 8
9
15 4 3 1 2 8 11 8 8
*/
int main()
{
	int i,j,k;
	int n = 0;
	while(scanf("%d",&n) && n)
	{		
		bool flag[65] = {0};
		int sum = 0;
		for(i = 0;i<n;i++)
		{
			scanf("%d",&data[i]);
			sum+=data[i];
		}
		qsort(data,n,4,cmp);
		for(i = data[0];;i++)
		{
			if(0 == sum%i)
			{
				dfs(flag,0,i,0,n);
				if(findout)
				{
					findout = false;
					break;
				}
			}
		}
	}
	return 0;
}

