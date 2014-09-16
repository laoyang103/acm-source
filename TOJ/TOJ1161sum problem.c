#include <stdio.h>
int main()
{
	int n,sum;
	while(scanf("%d",&n) == 1)
	{
		if(n%2 ==0)
		{
			sum=n/2;
			sum*=(n+1);
		}
		else
		{
			sum=(n+1)/2;
			sum*=n;
		}
		printf("%d\n\n",sum);
	}
	return 0;
}
