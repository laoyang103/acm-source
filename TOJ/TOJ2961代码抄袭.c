#include <stdio.h>
char srcStr[1001];
char destStr[1001];
int main()
{
	int t;
	int n1,n2;
	int r;
	int i,counter;
	scanf("%d",&t);
	while(t--)
	{
		r=0;
		scanf("%d%s",&n1,srcStr);
		scanf("%d%s",&n2,destStr);
		if(n1 == n2)
		{
			counter=0;
			for(i=0;i<n1;++i)
			{
				if(srcStr[i]==destStr[i])++counter;
			}
			if((double)counter/(double)n1 > 0.700)
			{
				r=1;
			}
		}
		if(r==1)puts("Yes");
		else puts("No");
	}
	return 0;
}
