#include<stdio.h>
int array[100001];//输入数据
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
			if(max < array[i])//找出最大和
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
		if(start > end)//预防遇上全为负数的数据，上面的计算会出现start>end
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
本题需要考虑特殊数据：全为负数的数据！
在含有非负数序列中，最大和序列的起始位和终止位必定是非负数。
序列的首（尾）向前（后）相加，其和必定减小。
如：
3 4 -8 1 2 9 -1
将每个数与他前面非负和相加
3 7 -1 1 3 12 11
显然最大和为12，起始点为4（1），终止点为6（9）
*/
