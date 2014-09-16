#include <stdio.h>
#include <math.h>
int isPrim(int a)
{
	int sq=sqrt(a);
	int i;
	for(i=2;i<=sq;++i)
	{
		if(a%i == 0)return 0;
	}
	return 1;
}
int main()
{
	int data,i;
	while(scanf("%d",&data)!=EOF)
	{
		for(i=data/2;i>2;--i)
		{
			if(isPrim(i)==1 && isPrim(data-i)==1)
			{
				break;
			}
		}
		printf("%d %d\n",i,data-i);
	}
	return 0;
}
