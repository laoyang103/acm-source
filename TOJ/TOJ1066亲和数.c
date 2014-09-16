#include<stdio.h>
#include<math.h>
int GetNumber(int number)
{
	int i,squareRoot;//平方根
	int sum=1;
	squareRoot=sqrt(number);//求出平方根
	for(i=2;i<=squareRoot;++i)//要从2开始，因为题意要求为真约数
	{
		if(number%i==0)sum=sum+i+number/i;
	}
	return sum;
}
int main()
{
	int testCount;
	int a,b;
	scanf("%d",&testCount);
	while(testCount--)
	{
		scanf("%d%d",&a,&b);
		if(GetNumber(a)==b && GetNumber(b)==a)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
