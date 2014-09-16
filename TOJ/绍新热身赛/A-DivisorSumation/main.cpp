#include <cstdio>
#include <cmath>
using namespace std;
int getDivSum(int d)
{
	int i;
	int n=d-1;
	int sum=1;
	for(i=2;i<=n;++i)
	{
		if(d%i == 0)
		{
			sum+=i;
		//	sum+=d/i;
		}
	}
	return sum;
}
int main()
{
	int n;
	int a;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&a);
		printf("%d\n",getDivSum(a));
	}
	return 0;
}
