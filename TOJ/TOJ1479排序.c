#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int data;
	int index;
}Array,*PArray;
int cmp_func(const void *pa,const void *pb)
{
	return ((PArray)pa)->data - ((PArray)pb)->data;
}
int main()
{
	Array array[10];
	int n=10,i;
	for(i=0;i<n;++i)
	{
		scanf("%d",&array[i].data);
		array[i].index=i+1;
	}
	qsort(array,n,sizeof(Array),cmp_func);
	for(i=0;i<n-1;++i)printf("%d ",array[i].data);
	printf("%d\n",array[i].data);
	for(i=0;i<n-1;++i)printf("%d ",array[i].index);
	printf("%d\n",array[i].index);
	return 0;
}
