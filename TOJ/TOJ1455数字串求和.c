#include<stdio.h>
int main()
{
	int a,b,n,i,sum;
	while(scanf("%d%d",&a,&n)==2)
	{
		sum=0;
		b=a;
		for(i=1;i<=n;++i)
		{
			sum+=b;
			b=b*10+a;
		}
		printf("%d\n",sum);
	}
	return 0;
}
