#include<stdio.h>
int main()
{
	int testCase=0;//��������
	int outlets=0;//������
	int sum=0;//�ܵĲ����
	int i,temp;
	scanf("%d",&testCase);
	while(testCase--)
	{
		scanf("%d",&outlets);
		sum=0;
		for(i=0;i<outlets;++i)
		{
			scanf("%d",&temp);
			sum+=temp;
		}
		//ÿ��һ����������Ҫռ��һ�����
		printf("%d\n",sum-(outlets-1));
	}
	return 0;
}
