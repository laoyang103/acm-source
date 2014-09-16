#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int best[4];
int bestType;
int bestCount;
int	tie;
int	search[4];
int input[25];
int kind;
int cmp(const void* a,const void* b)
{
	return *(int*)a > *(int*)b;
}
void func(int customer,int deep)
{
	int i=0;
	int temp[4];
	int type;
	int max1,max2;
	if(customer==0)
	{
		type=deep;
		memcpy(temp,search,sizeof(search));
		qsort(temp,deep,sizeof(int),cmp);
		for(i=1;i<deep;++i)
		{//计算种类
			if(temp[i-1]==temp[i])
				--type;
		}
		max1=input[temp[deep-1]];
		max2=input[best[deep-1]];
		if(type==bestType && deep==bestCount && max1==max2)
		{//判断是否为tie
			for(i=0;i<deep;++i)
				if(temp[i]!=best[i])
				{
					tie=1;
					return;
				}
			return;
		}
		else if(type>bestType || (type==bestType && deep<bestCount)|| (type==bestType && deep==bestCount && max1>max2))
		{//修改最优解
			bestType=type;
			bestCount=deep;
			tie=0;
			memcpy(best,temp,sizeof(temp));
		}
		return;
	}
	for(i=0;i<kind;++i)
	{
		if(customer-input[i]<0 || (deep>=3 && customer-input[i]!=0))
			return;
		search[deep]=i;
		func(customer-input[i],deep+1);
	}
}
int main()
{
	int customer;
	int i=0;
	while(scanf("%d",input+i)!=EOF)
	{
		if(input[i]==0)
		{
			kind=i;
			qsort(input,i,sizeof(int),cmp);
			while(scanf("%d",&customer),customer)
			{
				memset(best,0,sizeof(best));
				memset(search,0,sizeof(search));
				bestType=0;
				bestCount=0;
				tie=0;
				func(customer,0);
				if(bestType==0)
					printf("%d ---- none\n",customer);
				else if(tie)
					printf("%d (%d): tie\n",customer,bestType);
				else
				{
					printf("%d (%d):",customer,bestType);
					for(i=0;i<bestCount;++i)
						printf(" %d",input[best[i]]);
					printf("\n");
				}
			}
			i=0;
		}
		else ++i;
	}
	return 0;
}