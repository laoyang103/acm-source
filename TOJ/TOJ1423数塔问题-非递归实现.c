#include<stdio.h>
int array[100][100];//������������
int max(int a,int b)//�����������ֵ
{
	return a>b?a:b;
}
int DP(n)//��̬�滮
{
	int i,j;
	for(i=n-2;i>=0;--i)
	{
		for(j=0;j<=i;++j)
		{
			array[i][j]=array[i][j]+max(array[i+1][j],array[i+1][j+1]);
		}
	}
	return array[0][0];
}
int main()
{
	int testTimes;//������������
	int n,i,j;
	scanf("%d",&testTimes);
	while(testTimes--)
	{
		scanf("%d",&n);//����
		for(i=0;i<n;++i)
		{
			for(j=0;j<=i;++j)
			{
				scanf("%d",&array[i][j]);
			}
		}
		printf("%d\n",DP(n));
	}
	return 0;
}

