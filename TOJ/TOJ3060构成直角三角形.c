#include <stdio.h>
#include <math.h>
int isValidTrangle(int a,int b,int c)
{
	int r=0;
	int t;
	if((a+b > c) && (a+c > b) && (b+c >a))//是否可构成三角形
	{
		if(a>b){t=a;a=b;b=t;}
		if(a>c){t=a;a=c;c=t;}
		if(b>c){t=b;b=c;c=t;}
		if(c*c == a*a+b*b)//勾股定理
		{
			r=1;
		}
	}
	return r;
}
int main()
{
	int t;
	int a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(isValidTrangle(a,b,c))
		{
			puts("1");
		}
		else puts("0");
	}
	return 0;
}
