#include <stdio.h>
int main()
{
	int n,i;
	int last,now;
	int t;
	int sum;
	while(scanf("%d",&n),n)
	{
		sum=0;
		last=0;
		for(i=0;i<n;++i)
		{
			scanf("%d",&now);
			t=last-now;
			if(t<0) sum += (-t)*6+5;
			else if(t>0)sum += t*4+5;
			else sum += 5;
			last=now;
		}
		printf("%d\n",sum);
	}
	return 0;
}
