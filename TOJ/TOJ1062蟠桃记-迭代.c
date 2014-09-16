#include<stdio.h>
int peach[30];//桃子数量
void Calculate()//将所有的数量迭代的计算出来
{
	int i;
	peach[0]=1;
	for(i=1;i<30;++i)
	{
		peach[i]=(peach[i-1]+1)*2;
	}
}
int main()
{
	int input;
	Calculate();
	while(scanf("%d",&input),input)
	{
		printf("%d\n",peach[input-1]);
	}
	return 0;
}
