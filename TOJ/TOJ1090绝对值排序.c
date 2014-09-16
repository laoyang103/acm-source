#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int cmp(const void* a,const void* b)
{
	return abs(*(int*)a)<abs(*(int*)b);
}
int arr[100];
int main()
{
	int n,i;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;++i)
			scanf("%d",arr+i);
		qsort(arr,n,sizeof(int),cmp);
		for(i=0;i<n-1;++i)
			printf("%d ",arr[i]);
		printf("%d\n",arr[i]);
	}
}