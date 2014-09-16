#include <stdio.h>
char prim[10001];//������
void initPrim()//ɸѡ�������������
{
	int i,j;
	for(i=2;i<10001;++i)
	{
		if(prim[i]==1)continue;
		for(j=i*2;j<10001;j+=i)
		{
			prim[j]=1;
		}
	}
}
int counterPrimSum(int n)
{
	int half=n/2;
	int i;
	int counter=0;
	for(i=2;i<half;++i)//����ȡ��half����ĿҪ��ͬ��������
	{
		if(prim[i]==0 && prim[n-i]==0)
		{
			++counter;
		}
	}
	return counter;
}
int main()
{
	int n;
	initPrim();
	while(1)
	{
		scanf("%d",&n);
		if(n==0)break;
		printf("%d\n",counterPrimSum(n));
	}
	return 0;
}
