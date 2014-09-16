#include <cstdio>
int main()
{
	int t;
	__int64 a,b,c,d,v;
	scanf("%d",&t);
	while(t--)
	{
		v=0;
		scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&d);
		__int64 m,t;
		/*将abc按从小到大排序，从最大的开始切*/
		if(a>b){m=a;a=b;b=m;}
		if(a>c){m=a;a=c;c=m;}
		if(b>c){m=b;b=c;c=m;}
		
		m=c-b;//先尝试分c比b多出来的那部分
		if(m >= d)//分c足够了
		{
			c-=d;
		}
		else//不够分
		{
			m=c-a+b-a;//分b、c比a多出来的那部分
			if(m >= d)//分b、c就足够了
			{
				t=m-d;
				b=a+t/2;
				t-=t/2;
				c=a+t;
			}
			else//不够分，需要分a、b、c
			{
				t=d-m;//分了m个，还差t个
				//将t分成3份，在a的基础上都减去该3等份
				long long average=a;
				a=average-t/3;
				t-=t/3;
				b=average-t/2;
				t-=t/2;
				c=average-t;
			}
		}
		printf("%I64d\n",a*b*c);
	}
	return 0;
}
