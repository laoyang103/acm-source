#include <stdio.h>
int main()
{
	int n;
	int a,b;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&a,&b);
		if(a==b)
		{
			puts("These numbers are equal.");
		}
		else
		{
			printf("%d\n",(a>b?a:b));
		}
	}
	return 0;
}
