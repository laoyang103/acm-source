#include <stdio.h>
int average[101];
int getSum(int n)//获得等差数列前n项和
{
	return n*(n+1);//a1*n+n*(n-1)*d/2
}
int getAverage(int n,int m)//获得序列的平均值
{
	int t=n/m;//多少个分组
	int i=0;
	for(i=0;i<t;++i)
	{
		//Sij=Sj-Si
		average[i]=(getSum((i+1)*m)-getSum(i*m))/m;
	}
	if(n%m !=0)//有多出来的部分
	{
		average[i]=(getSum(n)-getSum(i*m))/(n-i*m);
		++i;
	}
	return i;//返回有多少个组
}
int main()
{
	int n,m;
	int i;
	int t;
	while(scanf("%d%d",&n,&m)==2)
	{
		t=getAverage(n,m);
		for(i=0;i<t-1;++i)
		{
			printf("%d ",average[i]);
		}
		printf("%d\n",average[i]);
	}
	return 0;
}
