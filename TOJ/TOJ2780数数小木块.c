#include <stdio.h>
int mark[101];
int main()
{
	int n;
	int i;
	int cur=1;
	mark[1]=1;
	for(i=2;i<101;++i)
	{
		cur=cur+i;
		mark[i]=mark[i-1]+cur;
	}
	scanf("%d",&n);
	printf("%d\n",mark[n]);
	return 0;
}
