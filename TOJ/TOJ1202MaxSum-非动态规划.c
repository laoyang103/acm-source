#include<stdio.h>
int array[100001];//��������
int main()
{
	int testCases,t;
	int n,i;
	int start,end,max;
	array[0]=0;
	scanf("%d",&testCases);
	for(t=1;t<=testCases;++t)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
		{
			scanf("%d",array+i);
			if(array[i-1]>=0)
			{
				array[i]+=array[i-1];
			}
		}
		max=-100000;
		for(i=1;i<=n;++i)
		{
			if(max < array[i])//�ҳ�����
			{
				max=array[i];
				end=i;
			}
		}
		for(i=end;i>0;--i)
		{
			if(array[i]<0)
			{
				break;
			}
		}
		start=i+1;
		if(start > end)//Ԥ������ȫΪ���������ݣ�����ļ�������start>end
		{
			start=end;
		}
		printf("Case %d:\n",t);
		printf("%d %d %d\n",max,start,end);
		if(t<testCases)
		{
			printf("\n");
		}
	}
	return 0;
}
/*
������Ҫ�����������ݣ�ȫΪ���������ݣ�
�ں��зǸ��������У��������е���ʼλ����ֹλ�ض��ǷǸ�����
���е��ף�β����ǰ������ӣ���ͱض���С��
�磺
3 4 -8 1 2 9 -1
��ÿ��������ǰ��Ǹ������
3 7 -1 1 3 12 11
��Ȼ����Ϊ12����ʼ��Ϊ4��1������ֹ��Ϊ6��9��
*/
