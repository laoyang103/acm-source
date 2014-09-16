#include <stdio.h>
int values[7]={1,2,5,10,20,50,100};

/*求找零钱方法数
data要找的零钱，
n为第几种零钱,其值对应于values数组中的值
amount为使用的张数
*/
int fn(int data,int n,int amount)
{
	int i=0,kind=0;
	if(0==n)
	{
		if(data+amount>100) return 0;//超过100张
		else	return 1;
	}
	if(data<=1) return 1;
	while(i*values[n]<=data)//i为使用第n层币的张数
	{//kind为方法数
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
