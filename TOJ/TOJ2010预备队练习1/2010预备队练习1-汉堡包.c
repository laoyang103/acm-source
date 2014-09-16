#include<stdio.h>
int main()
{
	int sum;
	int n,count;
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;
		while(n--)
		{
			scanf("%d",&count);
			if(count<=100)sum+=count;
		}
		printf("%d\n",sum);
	}
	return 0;
}
