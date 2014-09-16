#include <stdio.h>
#include <stdlib.h>
int array[40];
int Cmp(const void *a,const void *b)
{
	return *((int*)a) - *((int*)b);
}
int GetNumSum(int data)
{
	int sum=0;
	while(data)
	{
		sum+=data%10;
		data/=10;
	}
	return sum;
}
int main()
{
	int n,i;
	while(1)
	{
		scanf("%d",&n);
		if(0 == n)break;
		for(i=1;i<n*2;i+=2)
		{
			scanf("%d",array+i);
			array[i-1]=GetNumSum(array[i]);
		}
		qsort(array,n,sizeof(int)*2,Cmp);
		for(i=1;i<(n-1)*2;i+=2)
		{
			printf("%d ",array[i]);
		}
		printf("%d\n",array[i]);
	}
	return 0;
}
