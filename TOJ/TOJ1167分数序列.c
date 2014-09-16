#include<stdio.h>
int main()
{
	double result,a,b,t;
	int n,i;
	scanf("%d",&n);
	a=2.0;//分母
	b=1.0;//分子
	result=0.0;
	for(i=0;i<n;++i)
	{
		result+=a/b;
		t=a;
		a=a+b;//本次分母等于上次的分母与分子之和
		b=t;//本次分子等于上次分母
	}
	printf("%.6lf",result);
	return 0;
}
