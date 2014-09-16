#include <stdio.h>
#include <string.h>
int array[101];
int main()
{
	int testCases,i;
	int score;
	while(1)
	{
		scanf("%d",&testCases);
		if(0 == testCases)break;
		memset(array,0,sizeof(array));
		for(i=0;i<testCases;++i)
		{
			scanf("%d",&score);
			++array[score];
		}
		scanf("%d",&score);
		printf("%d\n",array[score]);
	}
	return 0;
}
