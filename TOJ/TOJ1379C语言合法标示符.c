#include <stdio.h>
int isValidName(char in[])
{
	int r=0;
	char ch;
	if(in[0] == '_' || 
		(in[0]>='a' && in[0]<='z') || 
		(in[0]>='A' && in[0]<='Z'))
	{
		++in;
		ch=*in;
		while(0 != ch)
		{
			if(ch=='_' || 
				(ch>='0' && ch<='9')||
				(ch>='A' && ch<='Z')||
				(ch>='a' && ch<='z'))
			{
				r=1;
			}
			else
			{
				r=0;
				break;
			}
			++in;
			ch=*in;
		}
	}
	return r;
}
int main()
{
	int n;
	char input[51];
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		gets(input);
		if(isValidName(input))
		{
			puts("yes");
		}
		else puts("no");
	}
	return 0;
}
