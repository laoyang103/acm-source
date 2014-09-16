//此题就是一道简单的排序题。
#include <stdio.h>
int score[128];
void quickSort(int left,int right)
{
	int l=left;
	int r=right;
	int key=score[l];//设定分割点
	if(left<right)
	{
		while(l<r)
		{
			while(l<r && score[r]<=key)--r;
			score[l]=score[r];
			while(l<r && score[l]>=key)++l;
			score[r]=score[l];
		}
		score[l]=key;//插入分割点的位置
		quickSort(left,l-1);//对分割点左部分执行快排
		quickSort(l+1,right);//对分割点右部分执行快排
	}
}
int main()
{
	int n,i;
	int m;
	scanf("%d",&n);
	for(i=1;i<=n;++i)//a[0]不用
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
