#include <stdio.h>
int main()
{
	int max,id;
	int temp;
	int n,i;
	while(scanf("%d",&n)==1)
	{
		max=-1;
		id=0;
		for(i=1;i<=n;++i)
		{
			scanf("%d",&temp);
			if(max<temp)
			{
				max=temp;
				id=i;
			}
		}
		printf("%d %d\n",max,id);
	}
	return 0;
}
