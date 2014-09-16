#include <stdio.h>
int destArray[2000];
int array1[1000];
int array2[1000];
void Combine(int va,int vb)//归并两数组
{
	int i=0;//array1下标
	int j=0;//array2下标
	int k=0;//destArray下标
	for(;i<va && j<vb;++k)
	{
		if(array1[i] < array2[j])
		{
			destArray[k]=array1[i++];
		}
		else destArray[k]=array2[j++];
	}
	while(i<va)
	{
		destArray[k++]=array1[i++];
	}
	while(j<vb)
	{
		destArray[k++]=array2[j++];
	}
}
int main()
{
	int testCases;
	int va,vb;
	int i;
	scanf("%d",&testCases);
	while(testCases--)
	{
		scanf("%d",&va);
		for(i=0;i<va;++i)
		{
			scanf("%d",array1+i);
		}
		scanf("%d",&vb);
		for(i=0;i<vb;++i)
		{
			scanf("%d",array2+i);
		}
		Combine(va,vb);
		va=va+vb;
		printf("%d",va);
		for(i=0;i<va;++i)
		{
			printf(" %d",destArray[i]);
		}
		printf("\n");
	}
	return 0;
}
