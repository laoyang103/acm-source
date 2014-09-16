#include <stdio.h>
int main()
{
	int n,x;
	int i;
	int data;
	int money;
	while(scanf("%d%d",&n,&x)!=EOF)
	{
		money=0;
		for(i=0;i<n;++i)
		{
			scanf("%d",&data);
			if(data < x)money+=data;
			else money+=x;
		}
		printf("%d\n",money);
	}
	return 0;
}
