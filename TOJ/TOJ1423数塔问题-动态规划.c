#include<stdio.h>
#include<string.h>
int array[100][100];//������������
int memory[100][100];//��̬�滮��������
int max(int a,int b)//�����������ֵ
{
	return a>b?a:b;
}
int DP(n,i,j)//��̬�滮
{
	if(i == n-1)//������ײ�
	{
		return array[i][j];
	}
	if(-1 == memory[i][j])//(i,j)δ��������������
	{
		memory[i][j]=max(DP(n,i+1,j),DP(n,i+1,j+1))+array[i][j];
	}
	return memory[i][j];
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
		memset(memory,-1,sizeof(memory));//������memory����Ԫ���ó�-1
		printf("%d\n",DP(n,0,0));
	}
	return 0;
}
/*
(i,j)����ÿ��ֻ���ߵ�(i+1,j)��(i+1,j+1)��������
��f(i,j)Ϊ����(i,j)���񵽴�ײ�������֮�ͣ�
�ɵ÷���f(i,j)=array(i,j)+max(f(i+1,j),f(i+1,j+1));
�ݹ���ֹ������������ײ�.
*/
