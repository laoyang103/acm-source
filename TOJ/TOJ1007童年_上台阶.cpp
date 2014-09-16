#include <cstdio>
int a[41];//保存斐波那契数
int main()
{
	a[1]=1;
	a[2]=2;
	for(int i=3;i<=40;++i)//计算斐波那契数
		a[i]=a[i-1]+a[i-2];
	int n;
	while(scanf("%d",&n),n)
		printf("%d\n",a[n]);//直接将斐波那契数列值输出
	return 0;
}