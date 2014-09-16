#include <stdio.h>
#include <stdlib.h>
int a[100];
int factorial(int n)
{
	int len=1;
	int i,j;
	int c;//进位
	div_t temp;
	a[0]=1;
	for(i=1;i<=n;++i)
	{
		c=0;
		for(j=0;j<len;++j)
		{
			temp=div(a[j]*i+c,10000);//div为求商、余函数
			a[j]=temp.rem;//获得商
			c=temp.quot;//获得余数
		}
		if(c>0)//进位
		{
			a[len++]=c;
		}
	}
	return len;
}
int main()
{
	int n;
	int len,i;
	while(1)
	{
		scanf("%d",&n);
		if(n<0)break;
		len=factorial(n);
		printf("%d",a[--len]);//输出最高位
		for(i=len-1;i>=0;--i)
		{
			printf("%4.4d",a[i]);
		}
		printf("\n");
	}
	return 0;
}
