#include <stdio.h>
int values[7]={1,2,5,10,20,50,100};

/*������Ǯ������
dataҪ�ҵ���Ǯ��
nΪ�ڼ�����Ǯ,��ֵ��Ӧ��values�����е�ֵ
amountΪʹ�õ�����
*/
int fn(int data,int n,int amount)
{
	int i=0,kind=0;
	if(0==n)
	{
		if(data+amount>100) return 0;//����100��
		else	return 1;
	}
	if(data<=1) return 1;
	while(i*values[n]<=data)//iΪʹ�õ�n��ҵ�����
	{//kindΪ������
		kind+=fn(data-i*values[n],n-1,amount+i);
		++i;
	}
	return kind;
}
int main()
{
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(0==n)break;
		else
		{
			printf("%d\n",fn(n,6,0));
		}
	}
	return 0;
}
