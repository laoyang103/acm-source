#include<stdio.h>
int a[1000];//渊子的马
int b[1000];//对手的马
//快速排序
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
		//先进行排序
		QuikSort(a,0,n-1);
		QuikSort(b,0,n-1);
		j=n;
		r=0;//记录获胜的次数
		for(i=n-1;i>=0;--i)
		{//倒序将自己的马和对手的相比较，只要能取胜，就让计数器r++，
		//然后，将自己的下一匹马和别人的下一匹马相比较，直到
		//获胜次数，超过马匹数的一半时为止，即r>=n/2+1。
		//此算法为o(n)算法。
			for(j=j-1;j>=0;--j)
				if(a[i]>b[j])
				{
					++r;
					break;
				}
			//这条判断语句比较重要，可以提早结束不必要的循环，
			//在TOJ中可节省15ms的时间，而达到0ms的好成绩
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