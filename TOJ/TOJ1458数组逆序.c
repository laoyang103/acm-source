#include <stdio.h>
#include <string.h>
int array[100];
int arrayTemp[100];
int main()
{
	int n,m,i;
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		scanf("%d",array+i);
	}
	scanf("%d",&m);
	memcpy(arrayTemp,array+n-m,sizeof(int)*m);
	memcpy(arrayTemp+m,array,sizeof(int)*(n-m));
	for(i=0;i<n-1;++i)
	{
		printf("%d ",arrayTemp[i]);
	}
	printf("%d",arrayTemp[i]);
	return 0;
}
/*非真实算法
	for(i=n-m;i<n;++i)
	{
		printf("%d ",array[i]);
	}
	for(i=0;i<n-m-1;++i)
	{
		printf("%d ",array[i]);
	}
	printf("%d\n",array[i]);
*/	
