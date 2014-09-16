#include <stdio.h>
#include <string.h>
char input[61];
int main()
{
	int t;
	int lastBit;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		gets(input);
		lastBit=input[strlen(input)-1]-48;
		if(lastBit%2 == 0)
		{
			puts("even");
		}
		else puts("odd");
	}
	return 0;
}
