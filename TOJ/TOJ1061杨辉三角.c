#include<stdio.h>
int array[30][30];//����������ǵ���
int Calculate()//�����������
{//��30�����ȫ�������
	int i,j;
	array[0][0]=1;
	for(i=1;i<30;++i)
	{
		array[i][0]=array[i][i]=1;
		for(j=1;j<=i;++j)
		{
			array[i][j]=array[i-1][j-1]+array[i-1][j];
		}
	}
}
void Output(int level)//�������
{
	int i,j;
	for(i=0;i<level;++i)
	{
		for(j=0;j<i;++j)
		{
			printf("%d ",array[i][j]);
		}
		printf("%d\n",array[i][j]);
	}
	printf("\n");
}
int main()
{
	int input;
	Calculate();
	while(scanf("%d",&input),input)
	{
		Output(input);
	}
	return 0;
}
