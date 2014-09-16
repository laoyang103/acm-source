#include <stdio.h>
int a[101]={1,10,2,3};
int A[101][10000];
int max(int a,int b)
{
	return a>b?a:b;
}
int jump(int i,int m)
{
	if(i<0)
	{
		return 0;
	}
	if(A[i][m]==0)
	{
		if(a[i]<=m)
		{
			A[i][m]=max(jump(i-1,a[i])+a[i],jump(i-1,m));
		}
		else
		{
			A[i][m]=jump(i-1,m);
		}
	}
	return A[i][m];
}

int main()
{
	printf("%d\n",jump(3,10000));
	return 0;
}
