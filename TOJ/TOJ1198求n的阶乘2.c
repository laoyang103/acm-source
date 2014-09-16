#include <stdio.h>
#include <stdlib.h>
int a[101][100];
int length[101];
int fact(int n)
{
	int len=length[n-1];
	int i;
	int c=0;//½øÎ»
	div_t temp;
	for(i=0;i<len;++i)
	{
		temp=div(a[n-1][i]*n+c,10000);
		a[n][i]=temp.rem;
		c=temp.quot;
	}
	if(c>0)
	{
		a[n][len++]=c;
	}
	length[n]=len;
	return len;
}
int factorial(int n)
{
	if(length[n]==0)
	{
		factorial(n-1);
		length[n]=fact(n);
	}
	return length[n];
}
int main()
{
	int n;
	int len,i;
	length[0]=1;
	a[0][0]=1;
	while(1)
	{
		scanf("%d",&n);
		if(n<0)break;
		len=factorial(n);
		printf("%d",a[n][--len]);
		for(i=len-1;i>=0;--i)
		{
			printf("%4.4d",a[n][i]);
		}
		printf("\n");
	}
	return 0;
}
