#include<stdio.h>
int main()
{
	int n,a,sum;
	while(scanf("%d",&n)!=EOF)
	{
		sum=1;
		while(n--)
		{
			scanf("%d",&a);
			if(a%2!=0)
				sum*=a;
		}
		printf("%d\n",sum);
	}
	return 0;
}