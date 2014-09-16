#include<stdio.h>
int main()
{
	int testCase=0;//测试组数
	int outlets=0;//插座数
	int sum=0;//总的插孔数
	int i,temp;
	scanf("%d",&testCase);
	while(testCase--)
	{
		scanf("%d",&outlets);
		sum=0;
		for(i=0;i<outlets;++i)
		{
			scanf("%d",&temp);
			sum+=temp;
		}
		//每连一个插座，都要占据一个插口
		printf("%d\n",sum-(outlets-1));
	}
	return 0;
}
