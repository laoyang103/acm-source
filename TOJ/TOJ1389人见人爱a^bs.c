#include <stdio.h>
int getExp(int a,int b)
{
	int t;
	if(a==0)return 0;
	else if(b==0)return 1;
	else if(b==1)return a;
	{
		t=getExp(a,b/2)%1000;
		t=(t*t)%1000;
		if(b%2!=0)
		{
			t=(t*a)%1000;
		}
		return t;
	}
}
int main()
{
	int a,b;
	while(1)
	{
		scanf("%d%d",&a,&b);
		if(a==0 && b==0)break;
		printf("%d\n",getExp(a%1000,b));
	}
	return 0;
}
