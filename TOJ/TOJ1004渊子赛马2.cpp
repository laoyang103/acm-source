#include<stdio.h>
#include<stdlib.h>
int a[1000];//渊子的马
int b[1000];//对手的马
int cmp(const void* a,const void* b)
{
	return (*(int*)a > *(int*)b)?1:-1;
}
int main()
{
	int n,i,j;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		for(i=0;i<n;++i)
			scanf("%d",&a[i]);
		for(i=0;i<n;++i)
			scanf("%d",&b[i]);
		qsort(a,n,sizeof(int),cmp);
		qsort(b,n,sizeof(int),cmp);
		for(i=(n-1)/2,j=0;i<n;++i,++j)
			if(a[i]<=b[j])			
				break;
		if(i>=n)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}