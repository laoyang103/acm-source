#include<stdio.h>
int main()
{
	int a,b;
	int max_a,max_b;
	int i,n;
	while(scanf("%d%d",&a,&b),a!=-1 && b!=-1)
	{
		max_a=1;
		max_b=1;
		for(i=1;i<=a;++i)
		{
			if(a%i==0)
			{
				++max_a;
			}
		}
		for(i=1;i<=b;++i)
		{
			if(b%i==0)
			{
				++max_b;
			}
		}
		printf("%d",a);
		if(max_a>max_b)printf(">");
		else if(max_a==max_b)printf("=");
		else printf("<");
		printf("%d\n",b);
	}
	return 0;
}
