#include <stdio.h>
#include <string.h>

char a[1001];
char b[1001];
char sum[1002];

char* getSum()
{
	int i=strlen(a)-1;
	int j=strlen(b)-1;
	int k=1000;
	memset(sum,0,sizeof(sum));
	for(;i>=0;--i,--k)
	{
		sum[k] = a[i]-48;
	}
	for(k=1000;j>=0;--j,--k)
	{
		sum[k] += b[j]-48;
		sum[k-1] += sum[k]/10;
		sum[k] = sum[k]%10 + 48;
	}
	//去掉前导0
	k=0;
	while(sum[k] != '0')++k;
	//判断最高位的进位
	if(sum[k] > '9')
	{
		sum[k-1]='1';
		sum[k] -= 10;
		--k;
	}
	return sum+k;
}
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;++i)
	{
		scanf("%s%s",a,b);
		printf("Case %d:\n",i);
		printf("%s + %s = %s\n",getSum());
		if(i != t)
		{
			printf("\n");
		}
	}
}
