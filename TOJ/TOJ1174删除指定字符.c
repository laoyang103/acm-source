#include <stdio.h>
int main()
{
	char str[256];
	char c;
	int i,j;
	gets(str);
	scanf("%c",&c);
	i=0;
	while(str[i])
	{
		if(str[i]==c)
		{
			j=i;
			while(1)
			{
				str[j]=str[j+1];
				if(str[j]==0)break;
				++j;
			};
		}
		else ++i;
	}
	puts(str);
	return 0;
}
