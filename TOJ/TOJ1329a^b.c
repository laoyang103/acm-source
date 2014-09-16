#include <stdio.h>
int getExp(int a,int b)//³¬Ê±
{
	int i;
	int r=1;
	for(i=0;i<b;++i)
	{
		r=(r*a)%10;
	}
	return r;
}
int getExp2(int a,int b)//ÕÛ°ëÇóÃÝ
{
	int r;
	if(0 == a) r=0;
	else if(0 == b) r = 1;
	else if(1 == b) r = a;
	else
	{
		r=getExp2(a,b/2)%10;
		r=r*r;
		if(b%2 != 0)
		{
			r*=a;
		}
		r=r%10;
	}
	return r;
}
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		printf("%d\n",getExp2(a%10,b));
	}
	return 0;
}
