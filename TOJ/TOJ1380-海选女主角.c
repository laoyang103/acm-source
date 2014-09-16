#include <stdio.h>
int abs(int a)
{
	if(a<0)a=-a;
	return a;
}
int main()
{
	int m,n;
	int i,j;
	int temp;
	int maxScore,mi,mj;
	int min=-2147483648;//注意此题需考虑特殊的特殊数据,当然也可以使用64位整数来做
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		maxScore=0;
		mi=1;
		mj=1;
		for(i=1;i<=m;++i)
		{
			for(j=1;j<=n;++j)
			{
				scanf("%d",&temp);
				if(maxScore!=min && (abs(maxScore) < abs(temp) || temp==min))
				{
					maxScore=temp;
					mi=i;
					mj=j;
				}
			}
		}
		printf("%d %d %d\n",mi,mj,maxScore);
	}
	return 0;
}
