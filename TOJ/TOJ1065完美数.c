#include<stdio.h>
int perfectNumber[5]={6, 28, 496, 8128, 33550336};
void PutOut(int left,int right)
{
	int i;
	int first=1;
	for(i=0;i<5;++i)
	{
		if(perfectNumber[i]<left)continue;
		if(perfectNumber[i]>=right)break;
		if(1==first)
		{
			printf("%d",perfectNumber[i]);
			first=0;
		}
		else printf(" %d",perfectNumber[i]);
	}
	if(1==first)printf("NO");
	printf("\n");
}
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)==2)
	{
		if(0==a && 0==b)break;
		PutOut(a,b);
	}
	return 0;
}
