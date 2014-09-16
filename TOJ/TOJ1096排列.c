#include<stdio.h>
void Out(int *arr)
{
	int i,j,k;
	for(i=0;i<3;++i)
		for(j=0;j<3;++j)
			if(i!=j)
				for(k=0;k<3;++k)
					if(i!=k && j!=k)
						printf("%d %d %d\n",arr[i],arr[j],arr[k]);
}
int main()
{
	int arr[4];
	int temp,i;
	scanf("%d%d%d%d",arr,arr+1,arr+2,arr+3);
	for(i=3;i>=0;--i)
	{
		temp=arr[3];
		arr[3]=arr[i];
		arr[i]=temp;
		Out(arr);
	}
	return 0;
}
/*
注意规律：1234
每次对三个数排列，
每次排列的数有123，124，134，234
第一组少4，第二组少3，第三组少2，第四组少1。
*/