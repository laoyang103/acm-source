#include <cstdio>
int a[41];//����쳲�������
int main()
{
	a[1]=1;
	a[2]=2;
	for(int i=3;i<=40;++i)//����쳲�������
		a[i]=a[i-1]+a[i-2];
	int n;
	while(scanf("%d",&n),n)
		printf("%d\n",a[n]);//ֱ�ӽ�쳲���������ֵ���
	return 0;
}