#include<stdio.h>
int main()
{
	int m,n,x,y,i;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n>m)
		{
			x=n;
			n=m;
			m=x;
		}
		x=y=0;
		for(i=n;i<=m;++i)
		{
			if(i%2==0)
				x+=i*i;
			else
				y+=i*i*i;
		}
		printf("%d %d\n",x,y);
	}
	return 0;
}