#include <stdio.h>
int isFirst;
int jiaogu(int n)//�ݹ�ⷨ
{
	if(n==1)return 1;
	if(n%2==0)return jiaogu(n/2);
	else
	{
		if(isFirst==1)
		{
			printf("%d",n);
			isFirst=0;
		}
		else printf(" %d",n);
		return jiaogu(3*n+1);
	}
}
int jiaogu2(int n)//�ǵݹ�ⷨ
{
	while(n!=1)
	{
		if(n%2==0)n/=2;
		else
		{
			if(isFirst==1)
			{
				printf("%d",n);
				isFirst=0;
			}
			else printf(" %d",n);
			n=n*3+1;
		}
	}
	return 1;
}
int main()
{
	int t;
	int n;
	scanf("%d",&t);
	while(t--)
	{
		isFirst=1;
		scanf("%d",&n);
		jiaogu2(n);//����ݹ���ǵݹ�ⷨЧ������
		if(isFirst==1)printf("No number can be output !");
		printf("\n");
	}
	return 0;
}
