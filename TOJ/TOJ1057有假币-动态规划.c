#include<stdio.h>
int max(int a,int b)
{
	return a>b?a:b;
}
int find(int c)
{
	if(c <= 1)
	{
		 return 0;
	}
	if(c <= 3)
	{
		 return 1;
	}
	//���ٱҷֳ� 3��
	else if(c % 3 == 0)//�պ�����
	{
	  return find(c/3)+1;
	}
	else//������ʱ���ж� c/3 �� c/3+1�����Ƚϴ���
	{//����find(c/3)һ��С��find(c/3+1),�˴�����ֱ��д�� return find(c/3+1)+1��
		return max(find(c/3),find(c/3+1))+1;
	}
}
int main()
{
 	int coin;
 	while(1)
	{
		scanf("%d",&coin);
		if(0 == coin)
		{
		 	 break;
		}
		printf("%d\n",find(coin));
	}
	system("pause");
	return 0;
} 
