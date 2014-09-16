#include <stdio.h>
int isFirst;
int jiaogu(int n)//递归解法
{
	if(n==1)return 1;
	if(n%2==0)return jiaogu(n/2);
	else
	{
		if(isFirst==1)
		{
			printf("%d",n);
			isFirst=0;
		}
		else printf(" %d",n);
		return jiaogu(3*n+1);
	}
}
int jiaogu2(int n)//非递归解法
{
	while(n!=1)
	{
		if(n%2==0)n/=2;
		else
		{
			if(isFirst==1)
			{
				printf("%d",n);
				isFirst=0;
			}
			else printf(" %d",n);
			n=n*3+1;
		}
	}
	return 1;
}
int main()
{
	int t;
	int n;
	scanf("%d",&t);
	while(t--)
	{
		isFirst=1;
		scanf("%d",&n);
		jiaogu2(n);//此题递归与非递归解法效率相差不大
		if(isFirst==1)printf("No number can be output !");
		printf("\n");
	}
	return 0;
}
