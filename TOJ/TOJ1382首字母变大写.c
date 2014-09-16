#include <stdio.h>
char* fomatStr(char in[])
{
	int i;
	if(in[0]>='a' && in[0]<='z')
	{
		in[0] -= 32;
	}
	i=1;
	while(0 != in[i])
	{
		if(in[i-1] == ' ')
		{
			if(in[i]>='a' && in[i]<='z')
			{
				in[i] -= 32;
			}
		}
		++i;
	}
	return in;
}
int main()
{
	char input[101];
	while(gets(input) != NULL)
	{
		puts(fomatStr(input));
	}
	return 0;
}
