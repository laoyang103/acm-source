#include <stdio.h>
int main()
{
	int n,m,i;
	double result;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m);
		result=0;
		for(i=1;i<=m;++i)
		{
			if(i%2==0)
			{
				result-=1.0/i;
			}
			else result+=1.0/i;
		}
		printf("%.2lf\n",result);
	}
	return 0;
}
