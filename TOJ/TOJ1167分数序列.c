#include<stdio.h>
int main()
{
	double result,a,b,t;
	int n,i;
	scanf("%d",&n);
	a=2.0;//��ĸ
	b=1.0;//����
	result=0.0;
	for(i=0;i<n;++i)
	{
		result+=a/b;
		t=a;
		a=a+b;//���η�ĸ�����ϴεķ�ĸ�����֮��
		b=t;//���η��ӵ����ϴη�ĸ
	}
	printf("%.6lf",result);
	return 0;
}
