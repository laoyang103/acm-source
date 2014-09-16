#include <stdio.h>
int main()
{
	int testCases;
	int a,b;
	scanf("%d",&testCases);
	while(testCases--)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",(a%100+b%100)%100);
	}
	return 0;
}
