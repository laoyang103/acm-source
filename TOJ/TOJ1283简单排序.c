#include<stdio.h>
#include<stdlib.h>
int array[1000];
int cmp_func(const void *a,const void *b)
{
	return *(int*)a - *(int*)b;
}
int main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;++i)scanf("%d",array+i);
		qsort(array,n,sizeof(int),cmp_func);
		printf("%d",array[0]);
		for(i=1;i<n;++i)printf(" %d",array[i]);
		printf("\n");
	}
	return 0;
}
