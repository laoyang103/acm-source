//�������һ���򵥵������⡣
#include <stdio.h>
#include <stdlib.h>
int score[128];
int cmp(const void *a,const void *b)
{
	return *(int*)b - *(int*)a;//����
}
int main()
{
	int n,i;
	int m;
	int counter=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)//a[0]����
	{
		scanf("%d",score+i);
	}
	scanf("%d",&m);
	qsort(score+1,n,sizeof(int),cmp);
	for(i=1;i<=n;++i)
	{
		if(m==score[i])
		{
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}
