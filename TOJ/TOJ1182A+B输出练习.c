#include <stdio.h>
int main()
{
	int n;
	int data;
	int sum;
	while(scanf("%d",&n),n)
	{
		sum=0;
		while(n--)
		{
			scanf("%d",&data);
			sum+=data;
		}
		printf("%d\n",sum);
	}
	return 0;
}
