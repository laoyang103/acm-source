#include <stdio.h>
int Pow(int base,int exp)//求base^exp
{
	int i=0;
	int result=1;
	for(;i<exp;++i)
	{
		result*=base;
	}
	return result;
}
int CountBesideOne(int num)//求num不含一的个数
{
	int result=0;
	int bit;
	int i=0;
	while(0 != num)
	{
		bit=num%10-1;
		if(bit <= 0)
		{
			bit=1;
		}
		result+=bit*Pow(9,i);
		num/=10;
		++i;
	}
	return result;
}
int main()
{
	int num;
	while(scanf("%d",&num),num)
	{
		printf("%d\n",num-CountBesideOne(num));
	}
	return 0;
}
