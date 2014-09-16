#include <stdio.h>
void PrintTriangle(int n)
{
	int i,j;
	for(i=0;i<n;++i)
	{
		for(j=0;j<=i;++j)
		{
			putchar('*');
		}
		putchar('\n');
	}
}
int main()
{
	int testCases;
	int n;
	scanf("%d",&testCases);
	while(testCases--)
	{
		scanf("%d",&n);
		PrintTriangle(n);
	}
	return 0;
}
