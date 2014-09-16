#include <stdio.h>
#include <string.h>
int memory[56];
int GetNum(int n)
{
	if(n<4)return n;
	else
	{
		if(0 == memory[n])
		{
			memory[n]=GetNum(n-3)+GetNum(n-1);
		}
		return memory[n];
	}
}
int main()
{
	int n;
	while(scanf("%d",&n),n)
	{
		memset(memory,0,sizeof(memory));
		printf("%d\n",GetNum(n));
	}
	return 0;
}
