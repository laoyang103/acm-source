#include<stdio.h>
int main()
{
	int a,b,c,temp;
	int testCase;
	scanf("%d",&testCase);
	while(testCase--)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a+b>c && a+c>b && b+c>a)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
