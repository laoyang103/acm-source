#include<stdio.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int main()
{
	int array[10];
	int cmp,index,i,n;
	scanf("%d%d",&n,&array[0]);
	cmp=array[0];
	index=0;
	for(i=1;i<n;++i)
	{
		scanf("%d",array+i);
		if(cmp > array[i])
		{
			cmp=array[i];
			index=i;
		}
	}
	swap(array+index,array);
	cmp=array[0];
	index=0;
	for(i=1;i<n;++i)
	{
		if(cmp < array[i])
		{
			cmp=array[i];
			index=i;
		}
	}	
	swap(array+index,array+n-1);
	for(i=0;i<n-1;++i)printf("%d ",array[i]);
	printf("%d",array[n-1]);
	return 0;
}
//要考虑数据2 3 1的情况,所以找最小和最大要分开进行
