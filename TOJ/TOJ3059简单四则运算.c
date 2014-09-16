#include <stdio.h>
int main()
{
	int n;
	int a,b;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&a,&b);
		if(a%b == 0)
		{
			printf("%d %d %d %d\n",a+b,a*b,a-b,a/b);
		}
		else
		{
			printf("%d %d %d %.2lf\n",a+b,a*b,a-b,(double)a/b);
		}
	}
	return 0;
}
