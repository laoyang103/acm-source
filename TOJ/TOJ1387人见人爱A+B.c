#include <stdio.h>
int main()
{
	int a[3],b[3];
	int t;
	int i;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<3;++i)
		{
			scanf("%d",a+i);
		}
		for(i=0;i<3;++i)
		{
			scanf("%d",b+i);
		}
		a[2] += b[2];
		a[1] += b[1]+a[2]/60;
		a[2] %= 60;
		a[0] += b[0]+a[1]/60;
		a[1] %= 60;
		printf("%d %d %d\n",a[0],a[1],a[2]);
	}
	return 0;
}
