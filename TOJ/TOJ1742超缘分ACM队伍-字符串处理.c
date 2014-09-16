#include <stdio.h>
#include <stdlib.h>
int birthday[1000][3];
char str[1024];
int cmp(const void *a,const void *b)
{
	int *pa=(int*)a;
	int *pb=(int*)b;
	if(pa[1]>pb[1])return 1;//比较月
	else if(pa[1]<pb[1])return -1;
	return pa[2]-pb[2];//比较日
}
int main()
{
	int n,i;
	int counter;//统计
	int t;
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		scanf("%s%s%s%d-%d-%d",str,str,str,
			&birthday[i][0],&birthday[i][1],&birthday[i][2]);
	}
	qsort(birthday,n,sizeof(int)*3,cmp);
	t=1;
	counter=0;
	for(i=1;i<n;++i)
	{
		if(birthday[i][1]==birthday[i-1][1]
			&& birthday[i][2]==birthday[i-1][2])
		{
			++t;
		}
		else
		{
			if(t==3)++counter;
			t=1;
		}
	}
	if(t==3)++counter;
	printf("%d\n",counter);
	return 0;
}
/*
6
mmm 665556 jiaojiang 1989-8-13
lp3 668685 yueqing 1984-5-22
xiaowu3 662495 wenzhou 1987-5-22
rsp3 667495 wenzhou 1988-4-17
bbb3 665567 jiaojiang 1999-4-17
mmm3 665556 jiaojiang 1989-4-17

3
dfdf dffd fdfd 1-1-1
dfdf dffd fdfd 1-1-2
dfdf dffd fdfd 1-1-3
*/
