#include <stdio.h>

int isKEqual(int a,int b,int k)
{
	int i=0;
	int r=0;
	while(0 != k)
	{
		if(a%10 == b%10)
		{
			a /= 10;
			b /= 10;
			--k;
		}
		else
		{
			break;
		}
	}
	if(0 == k)
	{
		r=1;
	}
	else r=0;
	return r;
}

int main()
{
	int a,b,k;
	while(1)
	{
		scanf("%d%d%d",&a,&b,&k);
		if(0==a && 0==b)
		{
			break;
		}
		if(isKEqual(a,b,k))
		{
			printf("-1\n");
		}
		else printf("%d\n",a+b);
	}
	return 0;
}
