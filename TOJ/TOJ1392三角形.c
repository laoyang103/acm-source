#include <stdio.h>
int main()
{
	int n;
	double a,b,c;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lf%lf%lf",&a,&b,&c);
		if((a+b>c) && (a+c>b) && (b+c>a))
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
	}
	return 0;
}
