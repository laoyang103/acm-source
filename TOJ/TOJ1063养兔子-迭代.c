#include <stdio.h>
__int64 rabbit[91];
int main()
{
	int input,i;
	rabbit[1]=1;
	rabbit[2]=2;
	for(i=3;i<=90;++i)
		rabbit[i]=rabbit[i-1]+rabbit[i-2];
	while(scanf("%d",&input),input)
	{
		printf("%I64d\n",rabbit[input]);
	}
	return 0;
}
