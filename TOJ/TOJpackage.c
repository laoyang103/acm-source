#include <stdio.h>
#include <string.h>
int package[1001][2];
int memory[1001][1001][2];
int Max(int a,int b)
{
	return a>b?a:b;
}
int Min(int a,int b)
{
	return a>b?b:a;
}
int DP(int n,int volume,int* minAmount)
{
	int minA;
	int minB;
	if(0==n)
	{
		*minAmount=0;
		return 0;
	}
	if(-1==memory[n][volume][0])
	{
		memory[n][volume][0]=Max(DP(n-1,volume,&minA),
			DP(n-1,volume-package[n][1],&minB)+package[n][0]);
		memory[n][volume][1]=Min(minA+1,minB);
	}
	*minAmount=memory[n][volume][1];
	return memory[n][volume][0];
}
int main()
{
	int testCases;
	int i,j;
	int n;
	int volume;
	int min;
	int value;
	scanf("%d",&testCases);
	while(testCases--)
	{
		scanf("%d%d",&n,&volume);
		for(i=1;i<=n;++i)
		{
			scanf("%d%d",&package[i][0],&package[i][1]);
		}
		memset(memory,-1,sizeof(memory));
		value=DP(n,volume,&min);
		printf("%d %d\n",value,min);
	}
	return 0;
}
