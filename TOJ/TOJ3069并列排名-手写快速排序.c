//�������һ���򵥵������⡣
#include <stdio.h>
int score[128];
void quickSort(int left,int right)
{
	int l=left;
	int r=right;
	int key=score[l];//�趨�ָ��
	if(left<right)
	{
		while(l<r)
		{
			while(l<r && score[r]<=key)--r;
			score[l]=score[r];
			while(l<r && score[l]>=key)++l;
			score[r]=score[l];
		}
		score[l]=key;//����ָ���λ��
		quickSort(left,l-1);//�Էָ���󲿷�ִ�п���
		quickSort(l+1,right);//�Էָ���Ҳ���ִ�п���
	}
}
int main()
{
	int n,i;
	int m;
	scanf("%d",&n);
	for(i=1;i<=n;++i)//a[0]����
	{
		scanf("%d",score+i);
	}
	scanf("%d",&m);
	quickSort(1,n);
	for(i=1;i<=n;++i)
	{
		if(m==score[i])
		{
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}
