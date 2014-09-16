#include <stdio.h>
int Gcd(int a,int b)
{
	if(0 == b)return a;
	else return Gcd(b,a%b);
}
int main()
{
	int a,b;
	while(1)
	{
		scanf("%d%d",&a,&b);
		if(a==0 && b==0)break;
		printf("%d\n",Gcd(a,b));
	}
	return 0;
}
