#include<stdio.h>
int a[1000];//Ԩ�ӵ���
int b[1000];//���ֵ���
//��������
void QuikSort(int* arr,int left,int right)
{
	if(left<right)
	{
		int i=left;
		int j=right;
		int key=arr[left];
		while(i<j)
		{
			while(i<j && arr[j]>=key)--j;
			arr[i]=arr[j];
			while(i<j && arr[i]<=key)++i;
			arr[j]=arr[i];
		}
		arr[i]=key;
		QuikSort(arr,left,i-1);
		QuikSort(arr,i+1,right);
	}
}
int main()
{
	int n,i,j,r;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		for(i=0;i<n;++i)
			scanf("%d",&a[i]);
		for(i=0;i<n;++i)
			scanf("%d",&b[i]);
		//�Ƚ�������
		QuikSort(a,0,n-1);
		QuikSort(b,0,n-1);
		j=n;
		r=0;//��¼��ʤ�Ĵ���
		for(i=n-1;i>=0;--i)
		{//�����Լ�����Ͷ��ֵ���Ƚϣ�ֻҪ��ȡʤ�����ü�����r++��
		//Ȼ�󣬽��Լ�����һƥ��ͱ��˵���һƥ����Ƚϣ�ֱ��
		//��ʤ������������ƥ����һ��ʱΪֹ����r>=n/2+1��
		//���㷨Ϊo(n)�㷨��
			for(j=j-1;j>=0;--j)
				if(a[i]>b[j])
				{
					++r;
					break;
				}
			//�����ж����Ƚ���Ҫ�����������������Ҫ��ѭ����
			//��TOJ�пɽ�ʡ15ms��ʱ�䣬���ﵽ0ms�ĺóɼ�
			if(r>=(n/2+1))
				break;
		}
		if(r>=(n/2+1))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}