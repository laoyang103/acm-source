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
	int n,i,j,r;
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
		j=n;
		r=0;//记录获胜的次数
		for(i=n-1;i>=0;--i)
		{
			for(j=j-1;j>=0;--j)
				if(a[i]>b[j])
				{
					++r;
					break;
				}
			if(r>=(n/2+1))
				break;
		}
		if(r>=(n/2+1))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}