#include<stdio.h>
int array[30][30];//存贮杨辉三角的数
int Calculate()//计算杨辉三角
{//将30层的数全计算出来
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
void Output(int level)//输出数据
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
