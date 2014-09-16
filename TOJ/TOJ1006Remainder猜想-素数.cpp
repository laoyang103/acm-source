#include<stdio.h>
#include<string.h>
#define MAX	10000000
char prim[MAX];
int main()
{
	int i,j;
	int count,n;
	memset(prim,1,sizeof(prim));
	for(i=2;i<10000;++i)
	{
		if(prim[i]!=0)
		{
			for(j=i*2;j<MAX;j+=i)
				prim[j]=0;
		}
	}
	while(scanf("%d",&n),n)
	{
		count=0;
		for(i=2;i<=n;++i)
			if(prim[i])
				count++;
		printf("%d\n",count);
	}
	return 0;
}