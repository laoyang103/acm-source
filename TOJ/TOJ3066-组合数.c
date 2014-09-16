#include <stdio.h>
__int64 nj[21];
void initNJ()
{
	int i;
	nj[0]=1;
	for(i=1;i<21;++i)
	{
		nj[i]=nj[i-1]*i;
	}
}
int main()
{
	int t;
	int n,m;
	__int64 zh;
	initNJ();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
		zh=nj[n]/nj[n-m];
		zh/=nj[m];
		printf("%I64d\n",zh);
	}
	return 0;
}
