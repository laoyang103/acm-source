#include<stdio.h>
int a[100][100];
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
			scanf("%d",&a[i][j]);
	for(i=0;i<n;++i)
	{
		for(j=0;j<n-1;++j)
			printf("%d ",a[j][i]);
		printf("%d\n",a[j][i]);
	}
}