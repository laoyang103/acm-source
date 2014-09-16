#include <stdio.h>
int main()
{
	int testCases;
	int n;
	double r;
	scanf("%d",&testCases);
	while(testCases--)
	{
		scanf("%d",&n);
		if(n<1000)r=n;
		else if(n<2000)r=n*0.95;
		else if(n<3000)r=n*0.90;
		else if(n<5000)r=n*0.85;
		else r=n*0.80;
		printf("%.1lf\n",r);
	}
	return 0;
}
