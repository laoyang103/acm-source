#include <stdio.h>
#include <math.h>
int f(int n)
{
	if(n==1)return 1;
	else return f(n/2)+1;
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",f(n));
	}
	return 0;
}
