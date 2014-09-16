#include<stdio.h>
#include<string.h>
int a[201][301];
int w[201],v[201];
int main()
{
	int i,j,m,n;
	int testCase;
	
	scanf("%d",&testCase);
	while(testCase--)
	{
		memset(a,0,sizeof(a));
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&w[i],&v[i]);
		}	
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(j-w[i]<0)
					a[i][j]=a[i-1][j];
				else if(a[i-1][j]>a[i-1][j-w[i]]+v[i])
					a[i][j]=a[i-1][j];
				else
					a[i][j]=a[i-1][j-w[i]]+v[i];
			}
		}
		printf("%d\n",a[n][m]);
	}
	return 0;
}
