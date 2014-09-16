#include <stdio.h>
#include <string.h>
int memory[201];
int getSum(int n)
{
	if(0 == memory[n])
	{
		memory[n]=getSum(n-1)+(n*(n+1))/2;
	}
	return memory[n];
}
int main()
{
	int t;
	int n;
	memory[1]=1;
	memory[2]=4;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",getSum(n));
	}
	return 0;
}
