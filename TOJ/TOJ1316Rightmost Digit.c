#include <stdio.h>
//��a��b���ݵ����һλ��
int getExp(int a,int b)
{
	int t=0;
	if(a==0)return 0;
	else if(b==0)return 1;
	else
	{
		t=getExp(a,b/2)%10;//��10���࣬������һλ��
		t=t*t;
		if(b%2==1)
		{
			t*=a;
		}
		t=t%10;
	}
	return t;
}
int main()
{
	int t;
	int n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",getExp(n%10,n));
	}
	return 0;
}
