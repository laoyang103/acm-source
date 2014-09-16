#include<stdio.h>
#include<stdlib.h>
int array[10001];
int compare(const void* a,const void* b)
{
	return *(int*)a - *(int*)b;
}
void sort(int n)
{
	int i,j,temp;
	for(i=n-1; i>0; --i)
	{
		for(j=0; j<i; ++j)
		{
			if(array[j] > array[j+1])
			{
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}
}
int main()
{
	int testCount=0;
	int arrayLength=0;
	int maxLength,tempLength;
	int i;
	scanf("%d",&testCount);
	while(testCount--)
	{
		scanf("%d",&arrayLength);
		for(i=0;i<arrayLength;++i)
			scanf("%d",array+i);
		qsort(array,arrayLength,sizeof(int),compare);
	//	sort(arrayLength);
		tempLength=maxLength=1;
		for(i=1;i<arrayLength;++i)
		{
			if(array[i]!=array[i-1])
			{
				if(maxLength<tempLength)
					maxLength=tempLength;
				tempLength=1;
			}
			else ++tempLength;
		}
		if(maxLength<tempLength)
			maxLength=tempLength;
		printf("%d\n",maxLength);
	}
	return 0;
}
