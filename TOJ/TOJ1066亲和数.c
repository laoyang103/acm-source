#include<stdio.h>
#include<math.h>
int GetNumber(int number)
{
	int i,squareRoot;//ƽ����
	int sum=1;
	squareRoot=sqrt(number);//���ƽ����
	for(i=2;i<=squareRoot;++i)//Ҫ��2��ʼ����Ϊ����Ҫ��Ϊ��Լ��
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
