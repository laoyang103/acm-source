#include <stdio.h>
int array[10001];

void insert(int n,int data,int pos)
{
	int i;
	--pos;
	for(i=n;i>=pos;--i)
	{
		array[i]=array[i-1];
	}
	array[pos]=data;
}

int main()
{
	int t;
	int n;
	int i;
	int p,q;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;++i)
		{
			scanf("%d",array+i);
		}
		scanf("%d%d",&p,&q);
		insert(n,p,q);
		for(i=0;i<n;++i)
		{
			printf("%d ",array[i]);
		}
		printf("%d\n",array[i]);
	}
	return 0;
}
