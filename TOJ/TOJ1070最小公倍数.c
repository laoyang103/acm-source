#include <stdio.h>
int gcd(int a,int b)//�����Լ��
{
	if(0==a%b)return b;
	return gcd(b,a%b);
}
int lcm(int a,int b)//����С������
{
	return a/gcd(a,b)*b;
}
int main()
{
	int n,i;
	int a,b;
	int r;
	while(scanf("%d",&n)==1)
	{
		scanf("%d",&a);
		r=a;
		for(i=1;i<n;++i)
		{
			scanf("%d",&b);
			r=lcm(r,b);
		}
		printf("%d\n",r);
	}
	return 0;
}
