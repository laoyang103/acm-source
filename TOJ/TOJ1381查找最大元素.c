#include <stdio.h>
int main()
{
	char str[101];
	char chMax;
	int i=0;
	while(gets(str))
	{
		i=0;
		chMax=0;
		while(str[i])
		{
			if(chMax < str[i])
			{
				chMax=str[i];
			}
			++i;
		}
		i=0;
		while(str[i])
		{
			putchar(str[i]);
			if(str[i] == chMax)
			{
				printf("(max)");
			}
			++i;
		}
		printf("\n");
	}
	return 0;
}
