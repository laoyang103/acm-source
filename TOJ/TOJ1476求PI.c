#include<stdio.h>
int main()
{
	int n,i;
	double result=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		result+=1.0/(4*i-3)-1.0/(4*i-1);
	}
	printf("%.5lf",result*4);
	return 0;
}
